--- gyp/common.gypi.orig	2015-02-15 04:18:51.000000000 +0900
+++ gyp/common.gypi	2015-02-17 18:08:07.000000000 +0900
@@ -161,9 +161,9 @@
       ['target_platform=="Linux"', {
         # enable_gtk_renderer represents if mozc_renderer is supported on Linux
         # or not.
-        'compiler_target': 'clang',
+        'compiler_target': '<(compiler_target)',
         'compiler_target_version_int': 305,  # Clang 3.5 or higher
-        'compiler_host': 'clang',
+        'compiler_host': '<(compiler_host)',
         'compiler_host_version_int': 305,  # Clang 3.5 or higher
         'enable_gtk_renderer%': 1,
       }, {  # else
@@ -208,6 +208,14 @@
     # installed. This option is only for Linux.
     'server_dir%': '/usr/lib/mozc',
 
+    # renderer_dir represents the directory where mozc_renderer is
+    # installed. This option is only for Linux.
+    'renderer_dir%': '/usr/lib/mozc',
+
+    # tool_dir represents the directory where mozc_tool is
+    # installed. This option is only for Linux.
+    'tool_dir%': '/usr/lib/mozc',
+
     # Represents the directory where the source code of protobuf is
     # extracted. This value is ignored when 'use_libprotobuf' is 1.
     'protobuf_root': '<(third_party_dir)/protobuf',
@@ -621,17 +629,20 @@
           ['compiler_target=="clang"', {
             'cflags': [
               '-Wtype-limits',
+	      '<@(cflags)',
             ],
             'cflags_cc': [
               '-Wno-covered-switch-default',
               '-Wno-unnamed-type-template-args',
               '-Wno-c++11-narrowing',
-              '-std=gnu++0x',
+              '-std=c++11',
+	      '<@(cflags_cc)',
             ],
           }],
-          ['compiler_target=="clang" or compiler_target=="gcc"', {
+          ['compiler_host=="gcc"', {
             'cflags_cc': [
-              '-std=gnu++0x',
+              '-std=gnu++11',
+	      '<@(cflags_cc)',
             ],
           }],
         ],
@@ -641,17 +652,20 @@
           ['compiler_host=="clang"', {
             'cflags': [
               '-Wtype-limits',
+	      '<@(cflags)',
             ],
             'cflags_cc': [
               '-Wno-covered-switch-default',
               '-Wno-unnamed-type-template-args',
               '-Wno-c++11-narrowing',
-              '-std=gnu++0x',
+              '-std=c++11',
+	      '<@(cflags_cc)',
             ],
           }],
-          ['compiler_host=="clang" or compiler_host=="gcc"', {
+          ['compiler_host=="gcc"', {
             'cflags_cc': [
-              '-std=gnu++0x',
+              '-std=gnu++11',
+	      '<@(cflags_cc)',
             ],
           }],
         ],
@@ -744,16 +758,27 @@
       ['OS=="linux"', {
         'defines': [
           'OS_LINUX',
+          'OS_FREEBSD',
+          'LOCALBASE="<@(localbase)"',
         ],
         'cflags': [
           '<@(warning_cflags)',
           '-fPIC',
           '-fno-exceptions',
+	  '<@(cflags)',
         ],
         'cflags_cc': [
           # We use deprecated <hash_map> and <hash_set> instead of upcoming
           # <unordered_map> and <unordered_set>.
           '-Wno-deprecated',
+	  '<@(cflags_cc)',
+        ],
+        'include_dirs': [
+          '<@(include_dirs)'
+        ],
+        'ldflags': [
+          '<@(ldflags)',
+	  '-fstack-protector',
         ],
         'conditions': [
           ['target_platform!="NaCl"', {
