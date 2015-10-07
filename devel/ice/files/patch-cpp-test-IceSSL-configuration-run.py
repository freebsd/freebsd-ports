--- cpp/test/IceSSL/configuration/run.py.orig	2015-06-23 15:30:20.000000000 +0000
+++ cpp/test/IceSSL/configuration/run.py	2015-09-16 18:16:01.933879982 +0000
@@ -33,7 +33,7 @@
     elif TestUtil.isLinux():
         for c in ["cacert1.pem", "cacert2.pem"]:
             pem = os.path.join(certsPath, c)
-            os.system("rm -f {dir}/`openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
+            os.system("rm -f {dir}/`%%OPENSSLBASE%%/bin/openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
 
 cleanup()
 atexit.register(cleanup)
@@ -43,7 +43,7 @@
     os.system("security create-keychain -p password %s" % keychainPath)
     for cert in ["s_rsa_ca1.p12", "c_rsa_ca1.p12"]:
         os.system("security import %s -f pkcs12 -A -P password -k %s" % (os.path.join(certsPath, cert), keychainPath))
-elif TestUtil.isLinux():
+elif TestUtil.isLinux() or TestUtil.isFreeBSD():
     #
     # Create copies of the CA certificates named after the subject
     # hash. This is used by the tests to find the CA certificates in
@@ -51,6 +51,6 @@
     #
     for c in ["cacert1.pem", "cacert2.pem"]:
         pem = os.path.join(certsPath, c)
-        os.system("cp {pem} {dir}/`openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
+        os.system("cp {pem} {dir}/`%%OPENSSLBASE%%/bin/openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
 
 TestUtil.clientServerTest(additionalClientOptions = '"%s"' % os.getcwd())
