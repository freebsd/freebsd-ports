--- src/Standalone/custommessagebox.cpp.orig	2021-11-25 00:56:56 UTC
+++ src/Standalone/custommessagebox.cpp
@@ -153,7 +153,7 @@ void CustomMessageBox::ErrorMessageBox(Supervisor* sv,
             type = Critical;
             error_message = TranslationString::GetString().translation_str.E_ENV_001;
             sv->scanning_status = ERROR;
-        }else if(sv->m_LastError == kSDITransferEventTypeCancel){
+        }else if(sv->m_LastError == (SDIError)kSDITransferEventTypeCancel){
             return;
         }else if(sv->m_LastError == kSDIErrorDataSend){
             type = Critical;
