--- ./src/Gui/Process.cpp.orig	Sat Feb 24 11:41:26 2007
+++ ./src/Gui/Process.cpp	Sun Apr 22 00:20:17 2007
@@ -232,7 +232,7 @@
   {
 #ifdef FC_OS_WIN32
     sprintf(szPath, "%s;%s", env["PATH"].latin1(), path.latin1());
-#elif defined (FC_OS_LINUX) || defined (FC_OS_CYGWIN)
+#elif defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
     sprintf(szPath, "%s:%s", env["PATH"].latin1(), path.latin1());
 #else
     Base::Console().Warning("Not yet implemented!\n");
@@ -243,7 +243,7 @@
   {
 #ifdef FC_OS_WIN32
     sprintf(szPath, "%s;%s", getenv("PATH"), path.latin1());
-#elif defined (FC_OS_LINUX) || defined (FC_OS_CYGWIN)
+#elif defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
     sprintf(szPath, "%s:%s", getenv("PATH"), path.latin1());
 #else
     Base::Console().Warning("Not yet implemented!\n");
@@ -276,7 +276,7 @@
   {
 #ifdef FC_OS_WIN32
     ::SetEnvironmentVariable (it.key().latin1(), it.data().latin1());
-#elif defined (FC_OS_LINUX) || defined (FC_OS_CYGWIN)
+#elif defined (FC_OS_LINUX) || defined(FC_OS_FREEBSD) || defined(FC_OS_CYGWIN)
     setenv(it.key().latin1(), it.data().latin1(), 1);
 #else
     Base::Console().Warning("Not yet implemented!\n");
