--- freebsd/redefine-syms.sh.orig	2005-06-09 18:22:58.000000000 +0800
+++ freebsd/redefine-syms.sh	2021-02-18 13:47:59.275802000 +0700
@@ -1,4 +1,8 @@
 #!/bin/sh
+( status=0
 for i in $*; do
 	objcopy --redefine-syms=redefine-syms.lst "$i"
-done
+	status=$(($status + $?))
+done 2>&1 >&3 | fgrep -v increased >&2
+  exit $status
+) 3>&1
