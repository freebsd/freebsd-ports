--- src/grpscan.h.orig	2020-09-03 06:19:21 UTC
+++ src/grpscan.h
@@ -31,7 +31,9 @@ struct grpfile {
 	int crcval;
 	int size;
 	struct grpfile *next;
-} grpfiles[numgrpfiles], *foundgrps;
+};
+
+extern struct grpfile grpfiles[numgrpfiles], *foundgrps;
 
 int ScanGroups(void);
 void FreeGroups(void);
