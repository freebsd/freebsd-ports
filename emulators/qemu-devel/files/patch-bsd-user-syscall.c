diff --git a/bsd-user/syscall.c b/bsd-user/syscall.c
index eb1cdf2..2c32637 100644
--- a/bsd-user/syscall.c
+++ b/bsd-user/syscall.c
@@ -212,7 +212,11 @@ static int sysctl_oldcvt(void *holdp, size_t holdlen, uint32_t kind)
         *(uint64_t *)holdp = tswap64(*(unsigned long *)holdp);
         break;
 #endif
+#if !defined(__FreeBSD_version) || __FreeBSD_version < 900031
     case CTLTYPE_QUAD:
+#else
+    case CTLTYPE_U64:
+#endif
         *(uint64_t *)holdp = tswap64(*(uint64_t *)holdp);
         break;
     case CTLTYPE_STRING:
