--- data/workflow/createtaxdb.sh.orig	2021-06-25 01:33:07 UTC
+++ data/workflow/createtaxdb.sh
@@ -27,6 +27,8 @@ STRATEGY=""
 if hasCommand aria2c; then STRATEGY="$STRATEGY ARIA"; fi
 if hasCommand curl;   then STRATEGY="$STRATEGY CURL"; fi
 if hasCommand wget;   then STRATEGY="$STRATEGY WGET"; fi
+# Part of FreeBSD base, need not be installed separately
+if hasCommand fetch;  then STRATEGY="$STRATEGY FETCH"; fi
 if [ "$STRATEGY" = "" ]; then
     fail "No download tool found in PATH. Please install aria2c, curl or wget."
 fi
@@ -47,6 +49,9 @@ downloadFile() {
             ;;
         WGET)
             wget -O "$OUTPUT" "$URL" && return 0
+            ;;
+        FETCH)
+            fetch -o "$OUTPUT" "$URL" && return 0
             ;;
         esac
     done
