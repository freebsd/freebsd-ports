--- modules/modperl.cpp.orig	2008-11-14 13:02:05.000000000 +0100
+++ modules/modperl.cpp	2008-11-14 13:03:02.000000000 +0100
@@ -984,8 +984,8 @@
 bool CModPerl::OnLoad(const CString & sArgs, CString & sMessage)
 {
 	int iArgc = 5;
-	const char * pArgv[] = { "", "-e", "0", "-T", "-w", NULL };
-	PERL_SYS_INIT3( &iArgc, (char ***)&pArgv, &environ );
+  char * pArgv[] = { "", "-e", "0", "-T", "-w", NULL };
+  PERL_SYS_INIT3( &iArgc, &pArgv, &environ );
 	m_pPerl = perl_alloc();
 	perl_construct(m_pPerl);
 
