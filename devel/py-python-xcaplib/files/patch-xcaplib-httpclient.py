--- xcaplib/httpclient.py.orig	2016-01-12 11:22:06 UTC
+++ xcaplib/httpclient.py
@@ -164,7 +164,7 @@ class HTTPClient(object):
                 return HTTPResponse.from_addinfourl(response)
             else:
                 raise RuntimeError('urllib2.open returned %r' % response)
-        except urllib2.HTTPError, e:
+        except urllib2.HTTPError as e:
             # Workaround for bug in urllib2 which doesn't reset the retry count
             # when a negative, but different that 401 or 407, response is
             # received. -Luci
