--- src/Standalone/custommessagebox.cpp.orig	2024-09-12 07:10:40 UTC
+++ src/Standalone/custommessagebox.cpp
@@ -150,7 +150,7 @@ void CustomMessageBox::ErrorMessageBox(Supervisor* sv,
             type = Critical;
             error_message = TranslationString::GetString().translation_str.E_ENV_001;
             sv->scanning_status = ERROR;
-        }else if(sv->m_LastError == kSDITransferEventTypeCancel){
+        }else if(sv->m_LastError == (SDIError)kSDITransferEventTypeCancel){
             return;
         }else if(sv->m_LastError == kSDIErrorDataSend){
             type = Critical;
