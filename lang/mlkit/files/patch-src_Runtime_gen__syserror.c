--- src/Runtime/gen_syserror.c.orig	2022-12-22 15:04:04 UTC
+++ src/Runtime/gen_syserror.c
@@ -48,7 +48,6 @@ struct syserr_entry srcErr[] = {
   {"ENETUNREACH",ENETUNREACH},
   {"ENFILE",ENFILE},
   {"ENOBUFS",ENOBUFS},
-  {"ENODATA",ENODATA},
   {"ENODEV",ENODEV},
   {"ENOENT",ENOENT},
   {"ENOEXEC",ENOEXEC},
@@ -58,8 +57,6 @@ struct syserr_entry srcErr[] = {
   {"ENOMSG",ENOMSG},
   {"ENOPROTOOPT",ENOPROTOOPT},
   {"ENOSPC",ENOSPC},
-  {"ENOSR",ENOSR},
-  {"ENOSTR",ENOSTR},
   {"ENOSYS", ENOSYS},
   {"ENOTCONN",ENOTCONN},
   {"ENOTDIR",ENOTDIR},
@@ -80,7 +77,6 @@ struct syserr_entry srcErr[] = {
   {"ESPIPE",ESPIPE},
   {"ESRCH",ESRCH},
   {"ESTALE",ESTALE},
-  {"ETIME",ETIME},
   {"ETIMEDOUT",ETIMEDOUT},
   {"ETXTBSY",ETXTBSY},
   {"EWOULDBLOCK",EWOULDBLOCK},
