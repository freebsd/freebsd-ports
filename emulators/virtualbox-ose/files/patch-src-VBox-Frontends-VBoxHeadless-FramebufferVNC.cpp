--- src/VBox/Frontends/VBoxHeadless/FramebufferVNC.cpp.orig	2012-05-12 19:50:26.807639833 +0100
+++ src/VBox/Frontends/VBoxHeadless/FramebufferVNC.cpp	2012-05-12 19:50:38.568636058 +0100
@@ -89,7 +89,10 @@
     vncServer = rfbGetScreen(0, NULL, mWidth, mHeight, 8, 3, 1);
     vncServer->screenData = (void*)this;
     if (mVncPort)
+    {
         vncServer->port = mVncPort;
+        vncServer->ipv6port = mVncPort;
+    }
     char *pszDesktopName;
     rc = RTStrAPrintf(&pszDesktopName, "%s - VirtualBox", pszName);
     if (rc >= 0)
