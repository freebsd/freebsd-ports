--- src/wp/ap/xp/ap_Dialog_Goto.cpp.orig	2021-07-03 15:46:07 UTC
+++ src/wp/ap/xp/ap_Dialog_Goto.cpp
@@ -69,12 +69,12 @@ void AP_Dialog_Goto::_setupJumpTargets(void)
 {
     const XAP_StringSet * pSS = m_pApp->getStringSet();
 
-    s_pJumpTargets[0] = ::g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Page));
-    s_pJumpTargets[1] = ::g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Line));
-    s_pJumpTargets[2] = ::g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Bookmark));
-    //s_pJumpTargets[2] = ::g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Picture)); //TODO
-    s_pJumpTargets[3] = ::g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_XMLid));    
-    s_pJumpTargets[4] = ::g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Annotation));    
+    s_pJumpTargets[0] = g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Page));
+    s_pJumpTargets[1] = g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Line));
+    s_pJumpTargets[2] = g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Bookmark));
+    //s_pJumpTargets[2] = g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Picture)); //TODO
+    s_pJumpTargets[3] = g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_XMLid));    
+    s_pJumpTargets[4] = g_strdup(pSS->getValue (AP_STRING_ID_DLG_Goto_Target_Annotation));    
 
 }
 
