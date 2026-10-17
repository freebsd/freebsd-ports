Description: The Basic auth header carried the repr of a bytes object
  ("Basic b'...'") on Python 3; decode the base64 token to str.
Issue ID: none
Changeset: none
TODO: Upstream is dead (no commits since 2018-12); master still has the bug.

--- pyformance/reporters/opentsdb_reporter.py.orig	2017-10-08 11:44:59 UTC
+++ pyformance/reporters/opentsdb_reporter.py
@@ -37,7 +37,7 @@ class OpenTSDBReporter(Reporter):
                                          data=json.dumps(metrics).encode("utf-8"),
                                          headers={'content-type': "application/json"})
                 authentication_data = "{0}:{1}".format(self.application_name, self.write_key)
-                auth_header = base64.b64encode(bytes(authentication_data.encode("utf-8")))
+                auth_header = base64.b64encode(authentication_data.encode("utf-8")).decode("ascii")
                 request.add_header("Authorization", "Basic {0}".format(auth_header))
                 urllib.urlopen(request)
             except Exception as e:
