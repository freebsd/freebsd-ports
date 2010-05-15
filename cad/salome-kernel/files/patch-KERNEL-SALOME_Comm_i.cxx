--- src/Communication/SALOME_Comm_i.cxx.orig	2009-12-01 20:58:49.000000000 +0600
+++ src/Communication/SALOME_Comm_i.cxx	2010-03-10 22:41:04.000000000 +0600
@@ -19,10 +19,14 @@
 //
 //  See http://www.salome-platform.org/ or email : webmaster.salome@opencascade.com
 //
-#include "SALOME_Comm_i.hxx"
 #ifndef WIN32
+#include <rpc/types.h>
 #include <rpc/xdr.h>
 #endif
+
+#include <cstdio>
+
+#include "SALOME_Comm_i.hxx"
 #include "omniORB4/poa.h"
 #include "omnithread.h"
 #include "Utils_SINGLETON.hxx"
@@ -32,6 +36,7 @@
 #include "SenderFactory.hxx"
 using namespace std;
 
+
 #ifndef WIN32
 CORBA::ORB_var &getGlobalORB(){
   ORB_INIT &init = *SINGLETON_<ORB_INIT>::Instance();
