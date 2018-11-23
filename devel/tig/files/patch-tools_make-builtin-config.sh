sed: 1: "s/\s*#.*//": RE error: trailing backslash (\)

cf. PR 229925

--- tools/make-builtin-config.sh.orig	2018-11-23 06:50:40 UTC
+++ tools/make-builtin-config.sh
@@ -21,7 +21,7 @@ TIGRC="${1:-tigrc}"
 
 read_tigrc() {
 	if test -z "$NO_BUILTIN_TIGRC"; then
-		sed 's/\s*#.*//' "$TIGRC" | sed 's,\\,\\\\\\\\,g' | sed 's,",\\\\",g' | sed 's/	\+/	/g'
+		sed 's/[[:space:]]*#.*//' "$TIGRC" | sed 's,\\,\\\\\\\\,g' | sed 's,",\\\\",g' | sed 's/	\+/	/g'
 	else
 		echo '#'
 	fi
