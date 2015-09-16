--- cpp/test/IceSSL/configuration/run.py.orig	2015-06-27 13:03:48.260735765 +0000
+++ cpp/test/IceSSL/configuration/run.py	2015-06-27 13:03:54.559736750 +0000
@@ -43,7 +43,7 @@
     os.system("security create-keychain -p password %s" % keychainPath)
     for cert in ["s_rsa_ca1.p12", "c_rsa_ca1.p12"]:
         os.system("security import %s -f pkcs12 -A -P password -k %s" % (os.path.join(certsPath, cert), keychainPath))
-elif TestUtil.isLinux():
+elif TestUtil.isLinux() or TestUtil.isFreeBSD():
     #
     # Create copies of the CA certificates named after the subject
     # hash. This is used by the tests to find the CA certificates in
