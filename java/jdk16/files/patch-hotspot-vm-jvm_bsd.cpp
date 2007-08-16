--- ../../hotspot/src/os/bsd/vm/jvm_bsd.cpp	28 Mar 2007 04:52:29 -0000	1.1
+++ ../../hotspot/src/os/bsd/vm/jvm_bsd.cpp	9 Aug 2007 16:12:56 -0000	1.3
@@ -116,8 +116,8 @@
 */
 
 struct siglabel {
-  char *name;
-  int   number;
+  const char *name;
+  int	number;
 };
 
 struct siglabel siglabels[] =
