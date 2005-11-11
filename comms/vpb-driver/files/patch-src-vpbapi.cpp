--- src/vpbapi.cpp	Tue Aug 30 14:59:02 2005
+++ src/vpbapi.cpp	Tue Oct  4 21:19:06 2005
@@ -516,7 +516,7 @@
 		   Comm   *c);
 
 static jmp_buf env;
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 static int check_3dnow();
 static int check_sse();
 #endif
@@ -3803,7 +3803,7 @@
 	
 	return(VPB_OK);
 }
-#ifdef linux
+#if defined(linux) || defined(__FreeBSD__)
 int WINAPI vpb_is_station(int h)
 {
 	extern int      vpb_pconf[12][12];
