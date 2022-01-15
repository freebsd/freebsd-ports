--- cpp/test/IceSSL/configuration/run.py.orig	2019-08-12 19:54:18 UTC
+++ cpp/test/IceSSL/configuration/run.py
@@ -33,7 +33,7 @@ def cleanup():
     elif TestUtil.isLinux():
         for c in ["cacert1.pem", "cacert2.pem"]:
             pem = os.path.join(certsPath, c)
-            os.system("rm -f {dir}/`openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
+            os.system("rm -f {dir}/`%%OPENSSLBASE%%/bin/openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
 
 cleanup()
 atexit.register(cleanup)
@@ -51,6 +51,6 @@ elif TestUtil.iceUseOpenSSL():
     #
     for c in ["cacert1.pem", "cacert2.pem"]:
         pem = os.path.join(certsPath, c)
-        os.system("cp {pem} {dir}/`openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
+        os.system("cp {pem} {dir}/`%%OPENSSLBASE%%/bin/openssl x509 -subject_hash -noout -in {pem}`.0".format(pem=pem, dir=certsPath))
 
 TestUtil.clientServerTest(additionalClientOptions = '"%s"' % os.getcwd())
