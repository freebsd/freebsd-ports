--- setup.py.orig	2018-07-19 22:01:29 UTC
+++ setup.py
@@ -85,7 +85,7 @@ setup(
         "graphql-core>=2.1,<3",
         "graphql-relay>=0.4.5,<1",
         "promise>=2.1,<3",
-        "aniso8601>=3,<4",
+        "aniso8601>=3",
     ],
     tests_require=tests_require,
     extras_require={
