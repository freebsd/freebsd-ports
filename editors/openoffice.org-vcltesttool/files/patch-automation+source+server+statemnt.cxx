#iZ 37204

Index: automation/source/server/statemnt.cxx
===================================================================
RCS file: /cvs/util/automation/source/server/statemnt.cxx,v
retrieving revision 1.18
diff -u -r1.18 statemnt.cxx
--- automation/source/server/statemnt.cxx	9 Nov 2004 16:52:40 -0000	1.18
+++ automation/source/server/statemnt.cxx	21 Nov 2004 03:30:37 -0000
@@ -2251,7 +2251,8 @@
 		{
 			pRet->GenReturn ( RET_Value, aSmartMethodId, String() );
 			GetTTSettings()->pTranslateWin->EnableTranslation();
-			ErrorBox( GetTTSettings()->pTranslateWin, TTProperties::GetSvtResId( TT_NO_CONTROL ) ).Execute();
+			ErrorBox err= ErrorBox(GetTTSettings()->pTranslateWin, TTProperties::GetSvtResId( TT_NO_CONTROL ));
+		        err.Execute();
 			GetTTSettings()->bToTop = TRUE;
 		}
 
