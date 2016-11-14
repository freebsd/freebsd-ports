Import FindLibinotify.cmake from https//git.reviewboard.kde.org/r/129316/

From 2da80872431a9dc169085a9edca8c79c49e7fade Mon Sep 17 00:00:00 2001
From: "Tobias C. Berner" <tcberner@gmail.com>
Date: Sun, 30 Oct 2016 01:22:58 +0200
Subject: [PATCH] Add new cmake module `FindLibinotify.cmake`.

FreeBSD also has inotify. However it is a library and not a kernel subsystem.
---
 find-modules/FindLibinotify.cmake | 71 +++++++++++++++++++++++++++++++++++++++
 1 file changed, 71 insertions(+)
 create mode 100644 find-modules/FindLibinotify.cmake

diff --git a/find-modules/FindLibinotify.cmake b/find-modules/FindLibinotify.cmake
new file mode 100644
index 0000000..fe1f35e
--- /dev/null
+++ find-modules/FindLibinotify.cmake
@@ -0,0 +1,71 @@
+#.rest:
+# FindLibinotify
+# --------------
+#
+# Try to find libinotiy on Unix like systems.
+#
+# This will define the following variables:
+#
+# ``LIBINOTIFY_FOUND``
+#    True if Libinotify is available
+# ``LIBINOTIFY_LIBRARIES``
+#    This has to be passed to target_link_libraries()
+# ``LIBINOTIFY_INCLUDE_DIRS``
+#    This has to be passed to target_include_directories()
+#
+
+#=============================================================================
+# Copyright 2016 Tobias C. Berner <tcberner@FreeBSD.org>
+#
+# Redistribution and use in source and binary forms, with or without
+# modification, are permitted provided that the following conditions
+# are met:
+#
+# 1. Redistributions of source code must retain the copyright
+#    notice, this list of conditions and the following disclaimer.
+# 2. Redistributions in binary form must reproduce the copyright
+#    notice, this list of conditions and the following disclaimer in the
+#    documentation and/or other materials provided with the distribution.
+# 3. The name of the author may not be used to endorse or promote products
+#    derived from this software without specific prior written permission.
+#
+# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
+# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
+# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
+# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
+# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
+# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
+# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
+# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
+# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
+# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+#=============================================================================
+
+find_path(LIBINOTIFY_INCLUDE_DIRS sys/inotify.h )
+
+if ( LIBINOTIFY_INCLUDE_DIRS )
+    # On Linux there is no library to link against, on the BSDs there is.
+    if ( CMAKE_SYSTEM_NAME MATCHES "Linux" )
+        set( LIBINOTIFY_FOUND TRUE )
+    else ()
+        find_library( LIBINOTIFY_LIBRARIES NAMES inotify )
+        include(FindPackageHandleStandardArgs)
+        find_package_handle_standard_args( Libinotify
+            FOUND_VAR
+                LIBINOTIFY_FOUND
+           REQUIRED_VARS
+                LIBINOTIFY_LIBRARIES
+                LIBINOTIFY_INCLUDE_DIRS
+        )
+        mark_as_advanced( LIBINOTIFY_LIBRARIES LIBINOTIFY_INCLUDE_DIRS )
+        include(FeatureSummary)
+        set_package_properties(Libinotify PROPERTIES
+            URL "https://github.com/dmatveev/libinotify-kqueue"
+            DESCRIPTION "inotify API on the *BSD family of operating systems."
+        )
+    endif ()
+else ()
+   set( LIBINOTIFY_FOUND FALSE )
+endif ()
+
+mark_as_advanced( LIBINOTIFY_FOUND )
--
2.10.1

