$FreeBSD$

--- ../ecos/host/tools/ecostest/common/eCosTest.h.orig	Tue Apr 18 23:51:58 2000
+++ ../ecos/host/tools/ecostest/common/eCosTest.h	Tue Mar 27 20:31:41 2007
@@ -199,7 +199,7 @@
   bool GetSizes();
 
   // Connect to a test server
-  static ServerStatus CeCosTest::Connect (LPCTSTR pszHostPort, CeCosSocket *&pSock, const ExecutionParameters &e,String &strInfo,Duration dTimeout=10*1000);
+  static ServerStatus Connect (LPCTSTR pszHostPort, CeCosSocket *&pSock, const ExecutionParameters &e,String &strInfo,Duration dTimeout=10*1000);
 
   // Log some output.  The accumulated output can be retrieved using Output()
   void Log (LPCTSTR  const pszFormat,...);
