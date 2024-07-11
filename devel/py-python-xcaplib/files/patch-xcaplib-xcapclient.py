--- xcaplib/xcapclient.py.orig	2016-01-12 11:22:06 UTC
+++ xcaplib/xcapclient.py
@@ -304,7 +304,7 @@ def run_completion(option, raise_ex=False):
     finally:
         for x in result:
             log(x)
-            print x
+            print(x)
 
 def complete_xpath(options, app, selector, action):
     client = make_xcapclient(options)
@@ -517,7 +517,7 @@ def main():
 
     try:
         result = client_request(client, action, options, node_selector)
-    except (urllib2.URLError, HTTPException), ex:
+    except (urllib2.URLError, HTTPException) as ex:
         sys.exit('FATAL: %s: %s' % (type(ex).__name__, ex))
     if result.status==401 and not options.password and interactive():
         authreq = result.headers.get('www-authenticate')
