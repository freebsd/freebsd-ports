--- LibFoundation/System/Wm4System.cpp
+++ LibFoundation/System/Wm4System.cpp
@@ -21,7 +21,7 @@
 #include <sys/stat.h>
 
 // support for GetTime
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
 #include <sys/time.h>
 static timeval gs_kInitial;
 static bool gs_bInitializedTime = false;
@@ -102,7 +102,7 @@
 //----------------------------------------------------------------------------
 double System::GetTime ()
 {
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__FreeBSD__)
     if (!gs_bInitializedTime)
     {
         gs_bInitializedTime = true;
