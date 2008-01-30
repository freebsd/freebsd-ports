--- ld/genscripts.sh.orig	Sun Aug 12 15:00:07 2007
+++ ld/genscripts.sh	Tue Jan 15 11:04:56 2008
@@ -390,30 +390,14 @@
     *" ${EMULATION_NAME} "*) COMPILE_IN=true;;
 esac
 
-if test -n "${BASH+set}"; then
-  source_em()
-  {
-    local current_script="$em_script"
-    em_script=$1
-    . $em_script
-    em_script=$current_script
-  }
-  fragment()
-  {
-    local lineno=$[${BASH_LINENO[0]} + 1]
-    echo >> e${EMULATION_NAME}.c "#line $lineno \"$em_script\""
-    cat >> e${EMULATION_NAME}.c
-  }
-else
-  source_em()
-  {
-    . $1
-  }
-  fragment()
-  {
-    cat >> e${EMULATION_NAME}.c
-  }
-fi
+source_em()
+{
+  . $1
+}
+fragment()
+{
+  cat >> e${EMULATION_NAME}.c
+}
 
 # Generate e${EMULATION_NAME}.c.
 # Start with an empty file, then the sourced .em script
