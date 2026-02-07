--- plugins/wordperfect/xp/ie_impexp_WordPerfect.cpp.orig	2013-04-07 15:53:03.000000000 +0200
+++ plugins/wordperfect/xp/ie_impexp_WordPerfect.cpp	2016-01-26 20:42:39.153642000 +0100
@@ -35,7 +35,6 @@
 ABI_PLUGIN_DECLARE("WordPerfect")
 
 static IE_Imp_WordPerfect_Sniffer * m_ImpSniffer = 0;
-static IE_Exp_WordPerfect_Sniffer * m_ExpSniffer = 0;
 
 #ifdef HAVE_LIBWPS
 static IE_Imp_MSWorks_Sniffer * m_MSWorks_ImpSniffer = 0;
@@ -49,13 +48,7 @@ int abi_plugin_register (XAP_ModuleInfo 
 		m_ImpSniffer = new IE_Imp_WordPerfect_Sniffer ();
 	}
 
-	if (!m_ExpSniffer)
-	{
-		m_ExpSniffer = new IE_Exp_WordPerfect_Sniffer ();
-	}
-
 	UT_ASSERT (m_ImpSniffer);
-	UT_ASSERT (m_ExpSniffer);
 
 #ifdef HAVE_LIBWPS
 	if (!m_MSWorks_ImpSniffer)
@@ -79,7 +72,7 @@ int abi_plugin_register (XAP_ModuleInfo 
 	mi->usage   = "No Usage";
 
 	IE_Imp::registerImporter (m_ImpSniffer);
-	//IE_Exp::registerExporter (m_ExpSniffer);
+
 	return 1;
 }
 
@@ -93,18 +86,11 @@ int abi_plugin_unregister (XAP_ModuleInf
 	mi->usage   = 0;
 
 	UT_ASSERT (m_ImpSniffer);
-	UT_ASSERT (m_ExpSniffer);
 
 	IE_Imp::unregisterImporter (m_ImpSniffer);
 	delete m_ImpSniffer;
 	m_ImpSniffer = 0;
 	
-	/*
-	IE_Exp::unregisterExporter (m_ExpSniffer);
-	delete m_ExpSniffer;
-	m_ExpSniffer = 0;
-	*/
-
 #ifdef HAVE_LIBWPS
 	IE_Imp::unregisterImporter (m_MSWorks_ImpSniffer);
 	delete m_MSWorks_ImpSniffer;
