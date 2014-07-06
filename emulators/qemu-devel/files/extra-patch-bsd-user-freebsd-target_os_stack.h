diff --git a/bsd-user/freebsd/target_os_stack.h b/bsd-user/freebsd/target_os_stack.h
index c84b69e..73aea8f 100644
--- a/bsd-user/freebsd/target_os_stack.h
+++ b/bsd-user/freebsd/target_os_stack.h
@@ -1,3 +1,22 @@
+/*
+ *  FreeBSD setup_initial_stack() implementation.
+ *
+ *  Copyright (c) 2013-14 Stacey D. Son
+ *
+ *  This program is free software; you can redistribute it and/or modify
+ *  it under the terms of the GNU General Public License as published by
+ *  the Free Software Foundation; either version 2 of the License, or
+ *  (at your option) any later version.
+ *
+ *  This program is distributed in the hope that it will be useful,
+ *  but WITHOUT ANY WARRANTY; without even the implied warranty of
+ *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+ *  GNU General Public License for more details.
+ *
+ *  You should have received a copy of the GNU General Public License
+ *  along with this program; if not, see <http://www.gnu.org/licenses/>.
+ */
+
 #ifndef _TARGET_OS_STACK_H_
 #define _TARGET_OS_STACK_H_
 
@@ -64,9 +83,7 @@ static inline int setup_initial_stack(struct bsd_binprm *bprm,
         return -1;
     }
     /* Add page sizes array. */
-    /* p -= sizeof(int); */
     p -= sizeof(abi_ulong);
-    /* if (put_user_u32(TARGET_PAGE_SIZE, p)) { */
     if (put_user_ual(TARGET_PAGE_SIZE, p)) {
         errno = EFAULT;
         return -1;
@@ -85,9 +102,9 @@ static inline int setup_initial_stack(struct bsd_binprm *bprm,
     }
 
     /* Make room for the argv and envp strings */
-    /* p = destp = roundup(p - TARGET_SPACE_USRSPACE - (TARGET_ARG_MAX - stringspace), sizeof(abi_ulong)); */
-    argvp = p - TARGET_SPACE_USRSPACE;
-    p = destp = roundup(p - TARGET_SPACE_USRSPACE - TARGET_ARG_MAX, sizeof(abi_ulong));
+    argvp = roundup(p - TARGET_SPACE_USRSPACE - (TARGET_ARG_MAX - stringspace),
+	sizeof(abi_ulong));
+    p = destp = p - TARGET_SPACE_USRSPACE - TARGET_ARG_MAX;
 
     /*
      * Add argv strings.  Note that the argv[] vectors are added by
