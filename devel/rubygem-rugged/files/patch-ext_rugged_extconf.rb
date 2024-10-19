# Remove broken libgit2 detection

--- ext/rugged/extconf.rb.orig	2024-10-19 10:29:11 UTC
+++ ext/rugged/extconf.rb
@@ -65,32 +65,6 @@ if arg_config("--use-system-libraries", !!ENV['RUGGED_
 
 if arg_config("--use-system-libraries", !!ENV['RUGGED_USE_SYSTEM_LIBRARIES'])
   puts "Building Rugged using system libraries.\n"
-
-  dir_config('git2').any? or pkg_config('libgit2')
-
-  major = minor = nil
-
-  File.readlines(File.join(LIBGIT2_DIR, "include", "git2", "version.h")).each do |line|
-    if !major && (matches = line.match(/^#define LIBGIT2_VER_MAJOR\s+([0-9]+)$/))
-      major = matches[1]
-      next
-    end
-
-    if !minor && (matches = line.match(/^#define LIBGIT2_VER_MINOR\s+([0-9]+)$/))
-      minor = matches[1]
-      next
-    end
-
-    break if major && minor
-  end
-
-  try_compile(<<-SRC) or abort "libgit2 version is not compatible, expected ~> #{major}.#{minor}.0"
-#include <git2/version.h>
-
-#if LIBGIT2_VER_MAJOR != #{major} || LIBGIT2_VER_MINOR != #{minor}
-#error libgit2 version is not compatible
-#endif
-  SRC
 else
   if !find_executable('cmake')
     abort "ERROR: CMake is required to build Rugged."
