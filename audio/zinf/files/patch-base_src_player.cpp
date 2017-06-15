--- base/src/player.cpp.orig	2004-02-02 17:39:35 UTC
+++ base/src/player.cpp
@@ -547,7 +547,7 @@ void Player::HandleSingleArg(char *arg)
         // who needs to get this, plm or dlm?
         bool giveToDLM = false;
         bool giveToTheme = false;
-        char* extension = NULL;
+        const char* extension = NULL;
 
         extension = strrchr(url.c_str(), '.');
 
@@ -1103,7 +1103,7 @@ char *
 Player::
 GetProtocol(const char *title)
 {
-   char *temp_proto;
+   const char *temp_proto;
    char *proto_return = NULL;
 
    temp_proto = strstr(title, "://");
@@ -1122,7 +1122,7 @@ char *
 Player::
 GetExtension(const char *title)
 {
-   char *temp_ext;
+   const char *temp_ext;
    char *ext_return = NULL;
    char *proto = NULL;
 
@@ -1961,15 +1961,14 @@ HandlePrefsChanged(Event *pEvent)
            m_context->prefs->GetPrefString(kProxyHostPref, &buffer);
        }
 
-       char *port = strchr(buffer.c_str(),':');
-       if (port) {
-           *port = '\0';
-           port++;
-       }
        string proxyAddr = buffer;
        int nPort = 80;
-       if (port && *port)
-           nPort = atoi(port);
+       size_t pos = buffer.find(':');
+       if (pos != string::npos) {
+          proxyAddr = buffer.substr(0, pos++);
+          if (pos < buffer.size())
+              nPort = atoi(buffer.substr(pos).c_str());
+       }
     }
 
 
