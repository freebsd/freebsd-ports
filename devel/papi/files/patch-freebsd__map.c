--- ./freebsd/map.c.orig	2008-04-26 04:19:39.000000000 -0400
+++ ./freebsd/map.c	2009-07-15 12:05:10.751726000 -0400
@@ -4,9 +4,9 @@
 
 /* 
 * File:    freebsd-map.c
-* CVS:     $Id: map.c,v 1.1 2008-04-26 08:19:39 servat Exp $
+* CVS:     $Id: map.c,v 1.4 2009/07/09 13:02:26 servat Exp $
 * Author:  Harald Servat
-*          harald.servat@gmail.com
+*          redcrash@gmail.com
 */
 
 #include SUBSTRATE
@@ -46,6 +46,18 @@
 	_papi_hwd_native_info[CPU_K8].map = K8Processor_map;
 	_papi_hwd_native_info[CPU_K8].info = K8Processor_info;
 
+	_papi_hwd_native_info[CPU_ATOM].map = AtomProcessor_map;
+	_papi_hwd_native_info[CPU_ATOM].info = AtomProcessor_info;
+
+	_papi_hwd_native_info[CPU_CORE].map = CoreProcessor_map;
+	_papi_hwd_native_info[CPU_CORE].info = CoreProcessor_info;
+
+	_papi_hwd_native_info[CPU_CORE2].map = Core2Processor_map;
+	_papi_hwd_native_info[CPU_CORE2].info = Core2Processor_info;
+
+	_papi_hwd_native_info[CPU_CORE2EXTREME].map = Core2ExtremeProcessor_map;
+	_papi_hwd_native_info[CPU_CORE2EXTREME].info = Core2ExtremeProcessor_info;
+
 	_papi_hwd_native_info[CPU_LAST].map = NULL;
 	_papi_hwd_native_info[CPU_LAST].info = NULL;
 }
