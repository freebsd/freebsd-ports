--- ros/src/IncludeLibrary/IncludeLibrary_stsgrpdef.h.orig	Fri Sep 21 09:55:04 2001
+++ ros/src/IncludeLibrary/IncludeLibrary_stsgrpdef.h	Thu Aug 10 21:50:09 2006
@@ -103,6 +103,10 @@
 #define GRP_OSD GRP_OSD_WNT
 #define GRP_NTD GRP_NTD_WNT
 
+# elif __FreeBSD__
+#define GRP_OSD GRP_OSD_UNX
+#define GRP_NTD GRP_NTD_UNX
+
 # elif UNX
 #define GRP_OSD GRP_OSD_UNX
 #define GRP_NTD GRP_NTD_UNX
