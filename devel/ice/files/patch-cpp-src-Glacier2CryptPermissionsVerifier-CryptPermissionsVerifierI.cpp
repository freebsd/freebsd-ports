--- cpp/src/Glacier2CryptPermissionsVerifier/CryptPermissionsVerifierI.cpp~	2016-10-05 16:59:08.000000000 +0200
+++ cpp/src/Glacier2CryptPermissionsVerifier/CryptPermissionsVerifierI.cpp	2016-10-11 23:40:30.829983908 +0200
@@ -200,7 +200,7 @@
     return p->second == crypt_r(password.c_str(), salt.c_str(), &data);
 #   else
     IceUtilInternal::MutexPtrLock<IceUtil::Mutex> lock(_staticMutex);
-    return p->second == crypt(password.c_str(), salt.c_str())
+    return p->second == crypt(password.c_str(), salt.c_str());
 #   endif
 #elif defined(__APPLE__) || defined(_WIN32)
     //
