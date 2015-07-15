--- cpp/src/Glacier2CryptPermissionsVerifier/CryptPermissionsVerifierI.cpp.orig	2015-06-23 15:30:20.000000000 +0000
+++ cpp/src/Glacier2CryptPermissionsVerifier/CryptPermissionsVerifierI.cpp	2015-06-27 17:04:09.625743300 +0000
@@ -17,6 +17,8 @@
 
 #if defined(__GLIBC__)
 #   include <crypt.h>
+#elif defined(__FreeBSD__)
+#   include <unistd.h>
 #elif defined(__APPLE__)
 #   include <CoreFoundation/CoreFoundation.h>
 #   include <Security/Security.h>
@@ -33,6 +35,28 @@
 namespace
 {
 
+#if defined(__FreeBSD__)
+IceUtil::Mutex* _staticMutex = 0;
+
+class Init
+{
+public:
+
+    Init()
+    {
+        _staticMutex = new IceUtil::Mutex;
+    }
+
+    ~Init()
+    {
+        delete _staticMutex;
+        _staticMutex = 0;
+    }
+};
+
+Init init;
+#endif
+
 class CryptPermissionsVerifierI : public PermissionsVerifier
 {
 public:
@@ -140,7 +164,7 @@
     {
         return false;
     }
-#if defined(__GLIBC__)
+#if defined(__GLIBC__) || defined(__FreeBSD__)
     size_t i = p->second.rfind('$');
     string salt;
     if(i == string::npos)
@@ -162,9 +186,14 @@
             return false;
         }
     }
+#   if defined(__GLIBC__)
     struct crypt_data data;
     data.initialized = 0;
     return p->second == crypt_r(password.c_str(), salt.c_str(), &data);
+#   else
+    IceUtilInternal::MutexPtrLock<IceUtil::Mutex> lock(_staticMutex);
+    return p->second == crypt(password.c_str(), salt.c_str());
+#   endif
 #elif defined(__APPLE__) || defined(_WIN32)    
     //
     // Pbkdf2 string format:
