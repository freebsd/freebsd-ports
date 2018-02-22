--- install.lua.orig	2018-02-22 04:51:23 UTC
+++ install.lua
@@ -76,7 +76,7 @@ else
    fh:write(([=[
 #!/bin/sh
 exec "%s" -e "package.path=[[%s/../src/?.lua;%s/../src/?/init.lua;]]..package.path" "%s/luacheck.lua" "$@"
-]=]):format(args.lua, '$(dirname "$0")', '$(dirname "$0")', '$(dirname "$0")'))
+]=]):format(args.lua, '$(dirname $(realpath "$0"))', '$(dirname $(realpath "$0"))', '$(dirname $(realpath "$0"))'))
 end
 
 fh:close()
