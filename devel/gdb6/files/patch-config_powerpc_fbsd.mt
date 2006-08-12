
$FreeBSD: /tmp/pcvs/ports/devel/gdb6/files/Attic/patch-config_powerpc_fbsd.mt,v 1.1 2006-08-12 20:54:37 obrien Exp $

--- /dev/null
+++ gdb/config/powerpc/fbsd.mt
@@ -0,0 +1,7 @@
+# Target: FreeBSD/PowerPC
+TDEPFILES= rs6000-tdep.o ppc-sysv-tdep.o ppcfbsd-tdep.o corelow.o \
+	solib.o solib-svr4.o
+TM_FILE= tm-ppc-eabi.h
+
+# SIM_OBS = remote-sim.o
+# SIM = ../sim/ppc/libsim.a
