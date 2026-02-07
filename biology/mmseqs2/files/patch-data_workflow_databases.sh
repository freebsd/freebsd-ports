--- data/workflow/databases.sh.orig	2024-12-11 10:31:20 UTC
+++ data/workflow/databases.sh
@@ -27,6 +27,8 @@ if hasCommand wget;   then STRATEGY="$STRATEGY WGET"; 
 if hasCommand aria2c; then STRATEGY="$STRATEGY ARIA"; fi
 if hasCommand curl;   then STRATEGY="$STRATEGY CURL"; fi
 if hasCommand wget;   then STRATEGY="$STRATEGY WGET"; fi
+# Part of FreeBSD base, need not be installed separately
+if hasCommand fetch;  then STRATEGY="$STRATEGY FETCH"; fi
 if [ "$STRATEGY" = "" ]; then
     fail "No download tool found in PATH. Please install aria2c, curl or wget."
 fi
@@ -56,6 +58,9 @@ downloadFile() {
                 mv -f -- "${OUTPUT}.wget" "${OUTPUT}"
                 return 0
             fi
+            ;;
+        FETCH)
+            fetch -o "$OUTPUT" "$URL" && return 0
             ;;
         esac
     done
