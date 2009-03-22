--- common/devices/unixbluetooth.c.orig	2008-10-05 12:14:31.000000000 +0200
+++ common/devices/unixbluetooth.c	2009-02-17 17:03:58.000000000 +0100
@@ -54,6 +54,8 @@
 #include <netgraph/bluetooth/include/ng_hci.h>
 #include <netgraph/bluetooth/include/ng_l2cap.h>
 #include <netgraph/bluetooth/include/ng_btsocket.h>
+#include <bluetooth.h>
+#include </usr/include/sdp.h>
 
 #define BTPROTO_RFCOMM BLUETOOTH_PROTO_RFCOMM
 #define BDADDR_ANY NG_HCI_BDADDR_ANY
@@ -86,11 +88,6 @@
 
 #endif	/* HAVE_BT_ATON */
 
-static int str2ba(const char *str, bdaddr_t *ba)
-{
-	return !bt_aton(str, ba);
-}
-
 #else	/* Linux / BlueZ support */
 
 #include <bluetooth/bluetooth.h>
@@ -100,6 +97,272 @@
 
 #endif
 
+#ifdef HAVE_BLUETOOTH_NETGRAPH	/* FreeBSD / netgraph */
+
+/*
+** FreeBSD version of the find_service_channel function.
+** Written by Guido Falsi <mad@madpilot.net>.
+** Contains code taken from FreeBSD's sdpcontrol and rfcomm_sppd
+** programs, which are Copyright (c) 2001-2003 Maksim Yevmenkin
+** <m_evmenkin@yahoo.com>.
+*/
+
+static int find_service_channel(bdaddr_t *adapter, bdaddr_t *device, int only_gnapplet, uint16_t svclass_id)
+{
+	uint8_t getchan = 0;
+	uint32_t i, good = 0;
+	char name[64];
+	void *ss = NULL;
+
+	uint32_t attrs[] =
+	{
+		SDP_ATTR_RANGE( SDP_ATTR_PRIMARY_LANGUAGE_BASE_ID + SDP_ATTR_SERVICE_NAME_OFFSET,
+			SDP_ATTR_PRIMARY_LANGUAGE_BASE_ID + SDP_ATTR_SERVICE_NAME_OFFSET),
+		SDP_ATTR_RANGE( SDP_ATTR_PROTOCOL_DESCRIPTOR_LIST,
+			SDP_ATTR_PROTOCOL_DESCRIPTOR_LIST),
+	};
+	#define attrs_len	(sizeof(attrs)/sizeof(attrs[0]))
+
+	/* Buffer for the attributes */
+	#define NRECS   25      /* request this much records from the SDP server */
+	#define BSIZE   256     /* one attribute buffer size */
+	static uint8_t          buffer[NRECS * attrs_len][BSIZE];
+
+	/* SDP attributes */
+	static sdp_attr_t       values[NRECS * attrs_len];
+	#define values_len      (sizeof(values)/sizeof(values[0]))
+
+	/* Initialize attribute values array */
+	for (i = 0; i < values_len; i ++) {
+		values[i].flags = SDP_ATTR_INVALID;
+		values[i].attr = 0;
+		values[i].vlen = BSIZE; 
+		values[i].value = buffer[i];
+	}
+
+	if ((ss = sdp_open(adapter, device)) == NULL)
+		return -1;
+
+	if (sdp_error(ss) != 0)
+	{
+		sdp_close(ss);
+		return -1;
+	}
+
+	if (sdp_search(ss, 1, &svclass_id, attrs_len, attrs, values_len, values) != 0)
+	{
+		sdp_close(ss);
+		return -1;
+	}
+
+	for (i = 0; i < values_len; i++)
+	{
+		if (values[i].flags != SDP_ATTR_OK)
+			break;
+
+		union {
+			uint8_t		uint8;
+			uint16_t	uint16;
+			uint32_t	uint32;
+			uint64_t	uint64;
+			int128_t	int128;
+		}			value;
+		uint8_t *start, *end;
+		uint32_t type, len;
+
+		start = values[i].value;
+		end = values[i].value + values[i].vlen;
+
+		switch (values[i].attr) {
+		case SDP_ATTR_PROTOCOL_DESCRIPTOR_LIST:
+			if(getchan) {
+				SDP_GET8(type, start);
+				switch (type) {
+				case SDP_DATA_SEQ8:
+					SDP_GET8(len, start);
+					break;
+
+				case SDP_DATA_SEQ16:
+					SDP_GET16(len, start);
+					break;
+
+				case SDP_DATA_SEQ32:
+					SDP_GET32(len, start);
+					break;
+
+				default:
+					sdp_close(ss);
+					return -1;
+					break;
+				}
+
+				SDP_GET8(type, start);
+				switch (type) {
+				case SDP_DATA_SEQ8:
+					SDP_GET8(len, start);
+					break;
+
+				case SDP_DATA_SEQ16:
+					SDP_GET16(len, start);
+					break;
+
+				case SDP_DATA_SEQ32:
+					SDP_GET32(len, start);
+					break;
+
+				default:
+					sdp_close(ss);
+					return -1;
+					break;
+				}
+
+				while (start < end) {
+					SDP_GET8(type, start);
+					switch (type) {
+					case SDP_DATA_UUID16:
+						SDP_GET16(value.uint16, start);
+						break;
+
+					case SDP_DATA_UUID32:
+						SDP_GET32(value.uint32, start);
+						break;
+
+					case SDP_DATA_UUID128:
+						SDP_GET_UUID128(&value.int128, start);
+						break;
+
+					default:
+						sdp_close(ss);
+						return -1;
+						break;
+					}
+					if(value.uint16 == 3) {
+						SDP_GET8(type, start);
+						switch (type) {
+						case SDP_DATA_UINT8:
+						case SDP_DATA_INT8:
+							SDP_GET8(value.uint8, start);
+							return value.uint8;
+							break;
+
+						case SDP_DATA_UINT16:
+						case SDP_DATA_INT16:
+							SDP_GET16(value.uint16, start);
+							return value.uint16;
+							break;
+
+						case SDP_DATA_UINT32:
+						case SDP_DATA_INT32:
+							SDP_GET32(value.uint32, start);
+							return value.uint32;
+							break;
+
+						default:
+							sdp_close(ss);
+							return -1;
+							break;
+						}
+					} else {
+						SDP_GET8(type, start);
+						switch (type) {
+						case SDP_DATA_SEQ8:
+						case SDP_DATA_UINT8:
+						case SDP_DATA_INT8:
+						case SDP_DATA_BOOL:
+							SDP_GET8(value.uint8, start);
+							break;
+
+						case SDP_DATA_SEQ16:
+						case SDP_DATA_UINT16:
+						case SDP_DATA_INT16:
+						case SDP_DATA_UUID16:
+							SDP_GET16(value.uint16, start);
+							break;
+
+						case SDP_DATA_SEQ32:
+						case SDP_DATA_UINT32:
+						case SDP_DATA_INT32:
+						case SDP_DATA_UUID32:
+							SDP_GET32(value.uint32, start);
+							break;
+
+						case SDP_DATA_UINT64:
+						case SDP_DATA_INT64:
+							SDP_GET64(value.uint64, start);
+							break;
+
+						case SDP_DATA_UINT128:
+						case SDP_DATA_INT128:
+							SDP_GET128(&value.int128, start);
+							break;
+
+						default:
+							sdp_close(ss);
+							return -1;
+							break;
+						}
+					}
+				}
+			}
+			start += len;
+			break;
+
+		case SDP_ATTR_PRIMARY_LANGUAGE_BASE_ID + SDP_ATTR_SERVICE_NAME_OFFSET:
+			SDP_GET8(type, start);
+			switch (type) {
+				case SDP_DATA_STR8:
+				case SDP_DATA_URL8:
+					SDP_GET8(len, start);
+					snprintf(name, sizeof(name), "%*.*s", len, len, (char *) start);
+					start += len;
+					break;
+
+				case SDP_DATA_STR16:
+				case SDP_DATA_URL16:
+					SDP_GET16(len, start);
+					snprintf(name, sizeof(name), "%*.*s", len, len, (char *) start);
+					start += len;
+					break;
+
+				case SDP_DATA_STR32:
+				case SDP_DATA_URL32:
+					SDP_GET32(len, start);
+					snprintf(name, sizeof(name), "%*.*s", len, len, (char *) start);
+					start += len;
+					break;
+
+				default:
+					sdp_close(ss);
+					return -1;
+			}
+			if (name == NULL)
+				return -1;
+
+			if (strcmp(name, "gnapplet") == 0) {
+				if (only_gnapplet != 0)
+					getchan = 1;
+				break;
+			}
+
+			if (strstr(name, "Nokia PC Suite") != NULL)
+				break;
+
+			if (strstr(name, "Bluetooth Serial Port") != NULL)
+				break;
+
+			if (strstr(name, "m-Router Connectivity") != NULL)
+				break;
+
+			getchan = 1;
+			break;
+		}
+	}
+
+	sdp_close(ss);
+	return -1;
+}
+
+#else
 /*
  * Taken from gnome-phone-manager
  */
@@ -204,6 +467,8 @@
 	return channel;
 }
 
+#endif
+
 static int get_serial_channel(bdaddr_t *device)
 {
 	bdaddr_t src;
@@ -211,9 +476,15 @@
 
 	bacpy(&src, BDADDR_ANY);
 
+#ifdef HAVE_BLUETOOTH_NETGRAPH	/* FreeBSD / netgraph */
+	channel = find_service_channel(&src, device, 0, SDP_SERVICE_CLASS_SERIAL_PORT);
+	if (channel < 0)
+		channel = find_service_channel(&src, device, 0, SDP_SERVICE_CLASS_DIALUP_NETWORKING);
+#else
 	channel = find_service_channel(&src, device, 0, SERIAL_PORT_SVCLASS_ID);
 	if (channel < 0)
 		channel = find_service_channel(&src, device, 0, DIALUP_NET_SVCLASS_ID);
+#endif
 
 	return channel;
 }
