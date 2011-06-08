--- libSoXt/src/SoXtRsrc.c++.orig	2011-06-08 14:39:34.000000000 +0200
+++ libSoXt/src/SoXtRsrc.c++	2011-06-08 14:39:43.000000000 +0200
@@ -145,7 +145,7 @@
     classList = new XrmQuark[listSize];
     for (q = 0, s = len - 1;
     	 s >= 0; q++, s--) {
-#if (_MIPS_SZPTR == 64 || __ia64)
+#if (_MIPS_SZPTR == 64 || __ia64 || __amd64__)
 	 nameList[q]  = (XrmQuark) ((long) nameplist[s]);
 	 classList[q] = (XrmQuark) ((long) classplist[s]);
 #else
