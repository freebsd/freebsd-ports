--- /dev/null	2010-02-04 14:44:47.000000000 -0500
+++ libjava/gnu/java/security/jce/prng/natVMSecureRandomWin32.cc	2010-02-04 11:59:08.000000000 -0500
@@ -0,0 +1,32 @@
+// natVMSecureRandomPosix.cc - Native part of VMSecureRandom class for POSIX.
+
+/* Copyright (C) 2009 Free Software Foundation
+
+   This file is part of libgcj.
+
+This software is copyrighted work licensed under the terms of the
+Libgcj License.  Please consult the file "LIBGCJ_LICENSE" for
+details.  */
+
+#include <config.h>
+
+#include <sys/types.h>
+#include <sys/stat.h>
+#include <fcntl.h>
+#include <unistd.h>
+#include <string.h>
+#include <errno.h>
+
+#include <gcj/cni.h>
+#include <java/lang/InternalError.h>
+#include <gnu/java/security/jce/prng/VMSecureRandom.h>
+
+jint
+gnu::java::security::jce::prng::VMSecureRandom::natGenerateSeed(jbyteArray byte_array, jint offset, jint length)
+{
+  if (length != 0)
+    throw new ::java::lang::InternalError
+      (JvNewStringLatin1 ("Error function not implemented for Win32 target."));
+  return 0;
+}
+
