--- gluegen/src/java/com/sun/gluegen/runtime/CPU.java.orig	2008-02-23 06:46:44.000000000 +1100
+++ gluegen/src/java/com/sun/gluegen/runtime/CPU.java	2008-06-09 18:38:20.000000000 +1000
@@ -64,6 +64,7 @@
         (os.startsWith("hp-ux") && cpu.equals("pa_risc2.0"))) {
       is32Bit = true;
     } else if ((os.startsWith("windows") && cpu.equals("amd64")) ||
+	       (os.startsWith("freebsd") && cpu.equals("amd64")) ||
                (os.startsWith("linux") && cpu.equals("amd64")) ||
                (os.startsWith("linux") && cpu.equals("x86_64")) ||
                (os.startsWith("linux") && cpu.equals("ia64")) ||
