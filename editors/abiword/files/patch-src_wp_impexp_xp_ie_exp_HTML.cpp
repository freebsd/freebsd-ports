--- src/wp/impexp/xp/ie_exp_HTML.cpp.orig	Mon Sep 22 14:46:23 2003
+++ src/wp/impexp/xp/ie_exp_HTML.cpp	Mon Sep 22 14:47:36 2003
@@ -776,7 +776,7 @@
 	void * vptr = 0;
 	m_tagStack.pop (&vptr);
 
-	if (reinterpret_cast<UT_uint32>(vptr) == tagID) return;
+	if (reinterpret_cast<unsigned long>(vptr) == tagID) return;
 
 	UT_DEBUGMSG(("WARNING: possible tag mis-match in XHTML output!\n"));
 }
@@ -820,7 +820,7 @@
 UT_uint32 s_HTML_Listener::tagTop ()
 {
 	void * vptr = 0;
-	if (m_tagStack.viewTop (&vptr)) return reinterpret_cast<UT_uint32>(vptr);
+	if (m_tagStack.viewTop (&vptr)) return reinterpret_cast<unsigned long>(vptr);
 	return 0;
 }
 
@@ -1890,7 +1890,7 @@
 {
 	void * vptr = 0;
 	m_utsListType.viewTop (&vptr);
-	return static_cast<UT_uint16>(reinterpret_cast<UT_uint32>(vptr));
+	return static_cast<UT_uint16>(reinterpret_cast<unsigned long>(vptr));
 }
 
 void s_HTML_Listener::listPush (UT_uint16 type, const char * ClassName)
@@ -1929,7 +1929,7 @@
 
 	void * vptr = 0;
 	m_utsListType.pop (&vptr);
-	UT_uint16 type = static_cast<UT_uint16>(reinterpret_cast<UT_uint32>(vptr));
+	UT_uint16 type = static_cast<UT_uint16>(reinterpret_cast<unsigned long>(vptr));
 
 	UT_uint32 tagID;
 
