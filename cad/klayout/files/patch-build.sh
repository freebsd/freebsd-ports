--- build.sh.orig	2019-02-23 17:34:47 UTC
+++ build.sh
@@ -482,7 +482,7 @@ echo "    Build directory: $BUILD"
 mkdir -p $BUILD
 
 # source the version script
-. $(dirname $(which $0))/version.sh
+. version.sh
 
 # qmake needs absolute paths, so we get them now:
 #   OSX does not have `readlink -f` command. Use equivalent Perl script.
@@ -495,11 +495,7 @@ else
 fi
 
 if [ "$IS_MAC" = "no" ]; then
-  if ( gmake -v >/dev/null 2>/dev/null ); then
     MAKE_PRG=gmake
-  else
-    MAKE_PRG=make
-  fi
 else
   MAKE_PRG=make
 fi
@@ -521,9 +517,9 @@ cd $BUILD
 
 # chose the right qmake
 if [ $HAVE_QT5 = 0 ]; then
-  export QT_SELECT=4
+  export QT_SELECT=qt4
 else
-  export QT_SELECT=5
+  export QT_SELECT=qt5
 fi
 
 $QMAKE -v
@@ -531,54 +527,55 @@ $QMAKE -v
 # Force a minimum rebuild because of version info
 touch $CURR_DIR/src/version/version.h
 
-qmake_options=(
+## XXX
+##  CONFIG=\"$CONFIG\"
+qmake_options="
   -recursive
-  CONFIG+="$CONFIG"
-  RUBYLIBFILE="$RUBYLIBFILE"
-  RUBYINCLUDE="$RUBYINCLUDE"
-  RUBYINCLUDE2="$RUBYINCLUDE2"
-  RUBYVERSIONCODE="$RUBYVERSIONCODE"
-  HAVE_RUBY="$HAVE_RUBY"
-  PYTHONLIBFILE="$PYTHONLIBFILE"
-  PYTHONINCLUDE="$PYTHONINCLUDE"
-  HAVE_PYTHON="$HAVE_PYTHON"
-  HAVE_QTBINDINGS="$HAVE_QTBINDINGS"
-  HAVE_64BIT_COORD="$HAVE_64BIT_COORD"
-  HAVE_QT5="$HAVE_QT5"
-  HAVE_CURL="$HAVE_CURL"
-  PREFIX="$BIN"
-  RPATH="$RPATH"
-  KLAYOUT_VERSION="$KLAYOUT_VERSION"
-  KLAYOUT_VERSION_DATE="$KLAYOUT_VERSION_DATE"
-  KLAYOUT_VERSION_REV="$KLAYOUT_VERSION_REV"
-)
+  RUBYLIBFILE=\"$RUBYLIBFILE\"
+  RUBYINCLUDE=\"$RUBYINCLUDE\"
+  RUBYINCLUDE2=\"$RUBYINCLUDE2\"
+  RUBYVERSIONCODE=\"$RUBYVERSIONCODE\"
+  HAVE_RUBY=\"$HAVE_RUBY\"
+  PYTHONLIBFILE=\"$PYTHONLIBFILE\"
+  PYTHONINCLUDE=\"$PYTHONINCLUDE\"
+  HAVE_PYTHON=\"$HAVE_PYTHON\"
+  HAVE_QTBINDINGS=\"$HAVE_QTBINDINGS\"
+  HAVE_64BIT_COORD=\"$HAVE_64BIT_COORD\"
+  HAVE_QT5=\"$HAVE_QT5\"
+  HAVE_CURL=\"$HAVE_CURL\"
+  PREFIX=\"$BIN\"
+  RPATH=\"$RPATH\"
+  KLAYOUT_VERSION=\"$KLAYOUT_VERSION\"
+  KLAYOUT_VERSION_DATE=\"$KLAYOUT_VERSION_DATE\"
+  KLAYOUT_VERSION_REV=\"$KLAYOUT_VERSION_REV\"
+"
 
 if [ $BUILD_EXPERT = 1 ]; then
-  qmake_options+=(
-    QMAKE_AR="$AR cqs"
-    QMAKE_LINK_C="$CC"
-    QMAKE_LINK_C_SHLIB="$CC"
-    QMAKE_LINK="$CXX"
-    QMAKE_LINK_SHLIB="$CXX"
-    QMAKE_OBJCOPY="$OBJCOPY"
+  qmake_options="$qmake_options
+    QMAKE_AR=\"$AR cqs\"
+    QMAKE_LINK_C=\"$CC\"
+    QMAKE_LINK_C_SHLIB=\"$CC\"
+    QMAKE_LINK=\"$CXX\"
+    QMAKE_LINK_SHLIB=\"$CXX\"
+    QMAKE_OBJCOPY=\"$OBJCOPY\"
     QMAKE_RANLIB=
     QMAKE_STRIP=
-    QMAKE_CC="$CC"
-    QMAKE_CXX="$CXX"
-    QMAKE_CFLAGS="$CFLAGS"
+    QMAKE_CC=\"$CC\"
+    QMAKE_CXX=\"$CXX\"
+    QMAKE_CFLAGS=\"$CFLAGS\"
     QMAKE_CFLAGS_RELEASE=
     QMAKE_CFLAGS_DEBUG=
-    QMAKE_CXXFLAGS="$CXXFLAGS"
+    QMAKE_CXXFLAGS=\"$CXXFLAGS\"
     QMAKE_CXXFLAGS_RELEASE=
     QMAKE_CXXFLAGS_DEBUG=
-    QMAKE_LFLAGS="$LDFLAGS"
+    QMAKE_LFLAGS=\"$LDFLAGS\"
     QMAKE_LFLAGS_RELEASE=
     QMAKE_LFLAGS_DEBUG=
-  )
+  "
 fi
 
-echo $QMAKE "$CURR_DIR/src/klayout.pro" "${qmake_options[@]}"
-$QMAKE "$CURR_DIR/src/klayout.pro" "${qmake_options[@]}"
+echo $QMAKE "$CURR_DIR/src/klayout.pro" ${qmake_options} QMAKE_CFLAGS="$CFLAGS"
+$QMAKE "$CURR_DIR/src/klayout.pro" ${qmake_options} QMAKE_CXXFLAGS="$CXXFLAGS" QMAKE_CFLAGS="$CFLAGS" QMAKE_LFLAGS="$LDFLAGS"
 
 cd $CURR_DIR
 echo ""
