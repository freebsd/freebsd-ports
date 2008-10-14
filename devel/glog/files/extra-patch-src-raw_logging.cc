--- src/raw_logging.cc.orig	2008-10-03 13:32:50.000000000 +0800
+++ src/raw_logging.cc	2008-10-14 13:34:22.000000000 +0800
@@ -87,7 +87,7 @@
     DoRawLog(&buf, &size, "%c%02d%02d %02d%02d%02d %08x %s:%d] RAW: ",
              LogSeverityNames[severity][0],
              1 + t.tm_mon, t.tm_mday, t.tm_hour, t.tm_min, t.tm_sec,
-             int(pthread_self()),
+             long(pthread_self()),
              basename(const_cast<char *>(file)), line);
   }
   va_list ap;
