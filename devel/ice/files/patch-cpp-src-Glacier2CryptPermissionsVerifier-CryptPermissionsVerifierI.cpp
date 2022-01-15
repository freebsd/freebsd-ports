--- cpp/src/Glacier2CryptPermissionsVerifier/CryptPermissionsVerifierI.cpp.orig	2019-08-12 19:54:18 UTC
+++ cpp/src/Glacier2CryptPermissionsVerifier/CryptPermissionsVerifierI.cpp
@@ -272,7 +272,7 @@ CryptPermissionsVerifierI::checkPermissions(const stri
     return p->second == crypt_r(password.c_str(), salt.c_str(), &data);
 #   else
     IceUtilInternal::MutexPtrLock<IceUtil::Mutex> lock(_staticMutex);
-    return p->second == crypt(password.c_str(), salt.c_str())
+    return p->second == crypt(password.c_str(), salt.c_str());
 #   endif
 #elif defined(__APPLE__) || defined(_WIN32)
     //
