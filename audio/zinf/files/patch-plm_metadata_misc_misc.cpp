--- plm/metadata/misc/misc.cpp.orig	2003-09-16 17:35:19 UTC
+++ plm/metadata/misc/misc.cpp
@@ -104,26 +104,11 @@ bool Misc::ReadMetaData(const char* url,
     if(!strncasecmp(url, "file://", 7) && !metadata->Time())
     {
         RegistryItem *lmcItem = NULL;
-        char* cp;
-
-        cp = strrchr(url, '.');
-        if(cp)
-        {
-            cp++;
-            
-            char temp[256];
-
-            strcpy(temp, cp);
-
-            cp = temp;
-
-            while(*cp)
-            {
-                *cp = toupper(*cp);
-                cp++;
-            }
-
-            string ext = temp;
+        const string temp(url);
+        size_t pos = temp.rfind('.');
+        if (pos != string::npos) {
+            string ext = temp.substr(++pos);
+            transform(ext.begin(), ext.end(), ext.begin(), ::toupper);
 
             ExtensionMap::const_iterator iter = m_extensions.find(ext);
             if(iter != m_extensions.end())
