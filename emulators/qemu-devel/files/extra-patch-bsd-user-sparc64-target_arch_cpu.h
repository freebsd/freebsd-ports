From nox Mon Sep 17 00:00:00 2001
From: Juergen Lock <nox@jelal.kn-bremen.de>
Date: 06 Jul 2014 13:23:00 +0200
Subject: sparc64-bsd-user: sync ccr before changing carry flag

Sync ccr so that changing carry flag manually after syscall works
properly.

Signed-off-by: Juergen Lock <nox@jelal.kn-bremen.de>

--- a/bsd-user/sparc64/target_arch_cpu.h
+++ b/bsd-user/sparc64/target_arch_cpu.h
@@ -77,6 +77,7 @@ static inline void target_cpu_loop(CPUSP
                                          env->regwptr[2], env->regwptr[3],
                                          env->regwptr[4], env->regwptr[5]);
             }
+            cpu_put_ccr(env, cpu_get_ccr(env));
             if ((unsigned int)ret >= (unsigned int)(-515)) {
                 ret = -ret;
 #if !defined(TARGET_ABI32)
