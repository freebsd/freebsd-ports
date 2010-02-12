--- src/Communication/SALOME_Comm_i.cxx.orig	2009-03-18 20:52:29.000000000 +0600
+++ src/Communication/SALOME_Comm_i.cxx	2009-05-20 10:21:06.000000000 +0700
@@ -19,10 +19,12 @@
 //
 //  See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
 //
-#include "SALOME_Comm_i.hxx"
 #ifndef WIN32
+#include <rpc/types.h>
 #include <rpc/xdr.h>
 #endif
+
+#include "SALOME_Comm_i.hxx"
 #include "omniORB4/poa.h"
 #include "omnithread.h"
 #include "Utils_SINGLETON.hxx"
@@ -32,6 +34,7 @@
 #include "SenderFactory.hxx"
 using namespace std;
 
+
 #ifndef WIN32
 CORBA::ORB_var &getGlobalORB(){
   ORB_INIT &init = *SINGLETON_<ORB_INIT>::Instance();
