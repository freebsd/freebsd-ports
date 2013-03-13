--- agent/lib/libstatsinfo.c.orig	2012-11-26 11:21:03.000000000 +0900
+++ agent/lib/libstatsinfo.c	2013-03-10 23:32:13.408438036 +0900
@@ -50,9 +50,16 @@
 #include "pgut/pgut-spi.h"
 #include "../common.h"
 
-#ifndef WIN32
+#if !defined(WIN32)
+#if defined(__FreeBSD__)
+#include <sys/resource.h>
+#include <sys/sysctl.h>
+#include <paths.h>
+#include <kvm.h>
+#else
 #include "linux/version.h"
 #endif
+#endif
 
 /* also adjust non-critial setting parameters? */
 /* #define ADJUST_NON_CRITICAL_SETTINGS */
@@ -1114,9 +1121,11 @@
 #define NUM_STAT_FIELDS_MIN		6
 
 /* not support a kernel that does not have the required fields at "/proc/stat" */
+#if !defined(__FreeBSD__)
 #if LINUX_VERSION_CODE < KERNEL_VERSION(2,5,41)
 #error kernel version 2.5.41 or later is required
 #endif
+#endif
 
 /*
  * statsinfo_cpustats - get cpu information
@@ -1155,6 +1164,64 @@
 	PG_RETURN_DATUM(get_cpustats(fcinfo, 0, 0, 0, 0));
 }
 
+#ifdef __FreeBSD__
+static Datum
+get_cpustats(FunctionCallInfo fcinfo,
+			 int64 prev_cpu_user,
+			 int64 prev_cpu_system,
+			 int64 prev_cpu_idle,
+			 int64 prev_cpu_iowait)
+{
+	TupleDesc		 tupdesc;
+	int64			 cpu_user;
+	int64			 cpu_system;
+	int64			 cpu_idle;
+	int64			 cpu_iowait;
+	HeapTuple		 tuple;
+	Datum			 values[NUM_CPUSTATS_COLS];
+	bool			 nulls[NUM_CPUSTATS_COLS];
+	long			 cp_time[CPUSTATES];
+	kvm_t			 *kd;
+	char			 errbuf[_POSIX2_LINE_MAX];
+
+	must_be_superuser();
+
+	/* Build a tuple descriptor for our result type */
+	if (get_call_result_type(fcinfo, NULL, &tupdesc) != TYPEFUNC_COMPOSITE)
+		elog(ERROR, "return type must be a row type");
+
+	Assert(tupdesc->natts == lengthof(values));
+
+	kd = kvm_openfiles(NULL, _PATH_DEVNULL, NULL, O_RDONLY, errbuf);
+	if (kd == NULL) {
+		elog(ERROR, "kvm_openfiles failed: %s", errbuf);
+	}
+	if (kvm_getcptime(kd, cp_time) == -1) {
+		elog(ERROR, "kvm_getcptime failed");
+	}
+
+	memset(nulls, 0, sizeof(nulls));
+	memset(values, 0, sizeof(values));
+
+	cpu_user = cp_time[CP_USER] + cp_time[CP_IDLE];
+	cpu_system = cp_time[CP_SYS];
+	cpu_idle = cp_time[CP_IDLE];
+	cpu_iowait = cp_time[CP_INTR];
+
+	values[0] = CStringGetTextDatum((char *)"cpu");
+	values[1] = Int64GetDatum(cpu_user);
+	values[2] = Int64GetDatum(cpu_system);
+	values[3] = Int64GetDatum(cpu_idle);
+	values[4] = Int64GetDatum(cpu_iowait);
+	values[5] = Int16GetDatum(cpu_user < prev_cpu_user ? 1 : 0);
+	values[6] = Int16GetDatum(cpu_system < prev_cpu_system ? 1 : 0);
+	values[7] = Int16GetDatum(cpu_idle < prev_cpu_idle ? 1 : 0);
+	values[8] = Int16GetDatum(cpu_iowait < prev_cpu_iowait ? 1 : 0);
+
+	tuple = heap_form_tuple(tupdesc, values, nulls);
+	return HeapTupleGetDatum(tuple);
+}
+#else
 static Datum
 get_cpustats(FunctionCallInfo fcinfo,
 			 int64 prev_cpu_user,
@@ -1239,6 +1306,7 @@
 
 	return HeapTupleGetDatum(tuple);
 }
+#endif
 
 /*
  * statsinfo_devicestats - get device information
@@ -1333,11 +1401,14 @@
 
 	for (row = 0; row < SPI_processed; row++)
 	{
+#if !defined(__FreeBSD__)
 		HeapTupleHeader prev_devicestats;
+#endif
 		char *device;
 		char *spcname;
 		char *dev_major;
 		char *dev_minor;
+#if !defined(__FreeBSD__)
 		char *dev_name = NULL;
 		int64 readsector;
 		int64 readtime;
@@ -1346,14 +1417,18 @@
 		int64 ioqueue;
 		int64 iototaltime;
 		char *record;
+#endif
 		char  regex[64];
 		List *devicenum = NIL;
+#if !defined(__FreeBSD__)
 		List *records = NIL;
 		List *fields = NIL;
 		int   nfield;
+#endif
 
 		device = SPI_getvalue(tuptable->vals[row], tuptable->tupdesc, 1);
 		spcname = SPI_getvalue(tuptable->vals[row], tuptable->tupdesc, 2);
+		elog(LOG, "device:%s, spc:%s\n", device, spcname);
 
 		if (prev_device)
 		{
@@ -1375,6 +1450,7 @@
 
 		snprintf(regex, lengthof(regex), "^\\s*%s\\s+%s\\s+", dev_major, dev_minor);
 
+#if !defined(__FreeBSD__)
 		/* extract device information */
 		if (exec_grep(FILE_DISKSTATS, regex, &records) <= 0)
 		{
@@ -1389,11 +1465,24 @@
 		record = b_trim((char *) list_nth(records, 0));
 
 		nfield = exec_split(record, "\\s+", &fields);
+#endif
 
 		memset(nulls, 0, sizeof(nulls));
 		memset(values, 0, sizeof(values));
 		spclist = list_truncate(spclist, 0);
 
+#if defined(__FreeBSD__)
+		values[0] = CStringGetTextDatum("");
+		values[1] = CStringGetTextDatum("");
+		values[2] = CStringGetTextDatum("");
+		values[2] = Int64GetDatum(0);
+		values[3] = Int64GetDatum(0);
+		values[4] = Int64GetDatum(0);
+		values[5] = Int64GetDatum(0);
+		values[6] = Int64GetDatum(0);
+		values[7] = Int64GetDatum(0);
+		values[8] = Int64GetDatum(0);
+#else
 		if (nfield  == NUM_DISKSTATS_FIELDS)
 		{
 			/* device_major */
@@ -1467,7 +1556,15 @@
 				(errcode(ERRCODE_DATA_EXCEPTION),
 				 errmsg("unexpected file format: \"%s\"", FILE_DISKSTATS),
 				 errdetail("number of fields is not corresponding")));
+#endif
 
+#if defined(__FreeBSD__)
+		values[9] = Int16GetDatum(0);
+		values[10] = Int16GetDatum(0);
+		values[11] = Int16GetDatum(0);
+		values[12] = Int16GetDatum(0);
+		values[13] = Int16GetDatum(0);
+#else
 		/* set the overflow flag if value is smaller than previous value */
 		prev_devicestats = search_devicestats(devicestats, dev_name);
 
@@ -1536,6 +1633,7 @@
 
 		spclist = lappend(spclist, spcname);
 		prev_device = device;
+#endif
 	}
 
 	/* store the last tuple */
@@ -1560,6 +1658,46 @@
 /*
  * statsinfo_loadavg - get loadavg information
  */
+#if defined(__FreeBSD__)
+Datum
+statsinfo_loadavg(PG_FUNCTION_ARGS)
+{
+	TupleDesc	tupdesc;
+	HeapTuple	tuple;
+	Datum		values[NUM_LOADAVG_COLS];
+	bool		nulls[NUM_LOADAVG_COLS];
+	kvm_t		*kd;
+	char		errbuf[_POSIX2_LINE_MAX];
+	double		loadavg[3];
+
+	must_be_superuser();
+
+	/* Build a tuple descriptor for our result type */
+	if (get_call_result_type(fcinfo, NULL, &tupdesc) != TYPEFUNC_COMPOSITE)
+		elog(ERROR, "return type must be a row type");
+
+	Assert(tupdesc->natts == lengthof(values));
+
+	kd = kvm_openfiles(NULL, _PATH_DEVNULL, NULL, O_RDONLY, errbuf);
+	if (kd == NULL) {
+		elog(ERROR, "kvm_openfiles failed: %s", errbuf);
+	}
+	if (kvm_getloadavg(kd, loadavg, 3) == -1) {
+		elog(ERROR, "kvm_getloadavg failed");
+	}
+
+	memset(nulls, 0, sizeof(nulls));
+	memset(values, 0, sizeof(values));
+
+	values[0] = Float4GetDatum(loadavg[0]);
+	values[1] = Float4GetDatum(loadavg[1]);
+	values[2] = Float4GetDatum(loadavg[2]);
+
+	tuple = heap_form_tuple(tupdesc, values, nulls);
+
+	return HeapTupleGetDatum(tuple);
+}
+#else
 Datum
 statsinfo_loadavg(PG_FUNCTION_ARGS)
 {
@@ -1622,6 +1760,7 @@
 
 	return HeapTupleGetDatum(tuple);
 }
+#endif
 
 #define FILE_MEMINFO		"/proc/meminfo"
 #define NUM_MEMORY_COLS		5
@@ -1641,6 +1780,37 @@
 /*
  * statsinfo_memory - get memory information
  */
+#if defined(__FreeBSD__)
+Datum
+statsinfo_memory(PG_FUNCTION_ARGS)
+{
+	TupleDesc		 tupdesc;
+	HeapTuple		 tuple;
+	Datum			 values[NUM_MEMORY_COLS];
+	bool			 nulls[NUM_MEMORY_COLS];
+
+	must_be_superuser();
+
+	/* Build a tuple descriptor for our result type */
+	if (get_call_result_type(fcinfo, NULL, &tupdesc) != TYPEFUNC_COMPOSITE)
+		elog(ERROR, "return type must be a row type");
+
+	Assert(tupdesc->natts == lengthof(values));
+
+	memset(nulls, 0, sizeof(nulls));
+	memset(values, 0, sizeof(values));
+
+	values[0] = Int64GetDatum(0);
+	values[1] = Int64GetDatum(0);
+	values[2] = Int64GetDatum(0);
+	values[3] = Int64GetDatum(0);
+	values[4] = Int64GetDatum(0);
+
+	tuple = heap_form_tuple(tupdesc, values, nulls);
+
+	return HeapTupleGetDatum(tuple);
+}
+#else
 Datum
 statsinfo_memory(PG_FUNCTION_ARGS)
 {
@@ -1746,6 +1916,7 @@
 
 	return HeapTupleGetDatum(tuple);
 }
+#endif
 
 #define FILE_PROFILE		"/proc/systemtap/statsinfo_prof/profile"
 #define NUM_PROFILE_COLS	3
@@ -1754,6 +1925,13 @@
 /*
  * statsinfo_profile - get profile information
  */
+#if defined(x__FreeBSD__)
+Datum
+statsinfo_profile(PG_FUNCTION_ARGS)
+{
+	PG_RETURN_VOID();
+}
+#else
 Datum
 statsinfo_profile(PG_FUNCTION_ARGS)
 {
@@ -1863,6 +2041,7 @@
 
 	PG_RETURN_VOID();
 }
+#endif
 
 static void
 checked_write(int fd, const void *buf, int size)
