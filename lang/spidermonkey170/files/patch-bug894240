commit 19a4ba5c90a9
Author: Mike Hommey <mh+mozilla@glandium.org>
Date:   Wed Jul 17 16:16:55 2013 +0900

    Bug 894240 - Fix pointer dereference in js::cli::OptionParser::extractValue. r=Waldo
---
 js/src/shell/jsoptparse.cpp | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

--- shell/jsoptparse.cpp.orig	2013-02-11 22:33:23 UTC
+++ shell/jsoptparse.cpp
@@ -243,7 +243,7 @@ OptionParser::extractValue(size_t argc, char **argv, s
     char *eq = strchr(argv[*i], '=');
     if (eq) {
         *value = eq + 1;
-        if (value[0] == '\0')
+        if (*value[0] == '\0')
             return error("A value is required for option %.*s", eq - argv[*i], argv[*i]);
         return Okay;
     }
