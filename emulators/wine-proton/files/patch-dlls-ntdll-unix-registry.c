From: Gerald Pfeifer <gerald@pfeifer.com>
To: wine-devel@winehq.org
Date: Sat, 18 Jul 2020 12:02:58 +0300 (EEST)
Subject: [PATCH] ntdll: Include <signal.h> for sigset_t

commit 7053b7c615b44e7112ab8fb4c056206d32b6f1c9
Author: Alexandre Julliard <julliard@winehq.org>
Date:   Fri Jul 17 11:46:15 2020 +0200

    ntdll: Move the registry system calls to the Unix library.
    
    Signed-off-by: Alexandre Julliard <julliard@winehq.org>

broke non-Linux platforms since sigset_t isn't necessarily defined
based on the #include statements in the new dlls/ntdll/unix/registry.c.

This fixes it.

Observed and tested on FreeBSD 11.4/i386.

Gerald

Signed-off-by: Gerald Pfeifer <gerald@pfeifer.com>
---
 dlls/ntdll/unix/registry.c | 1 +
 1 file changed, 1 insertion(+)

diff --git a/dlls/ntdll/unix/registry.c b/dlls/ntdll/unix/registry.c
index f94c8ff98e..6d58361818 100644
--- dlls/ntdll/unix/registry.c
+++ dlls/ntdll/unix/registry.c
@@ -25,6 +25,7 @@
 #pragma makedep unix
 #endif
 
+#include <signal.h>
 #include <stdarg.h>
 #include <string.h>
 
-- 
2.27.0

