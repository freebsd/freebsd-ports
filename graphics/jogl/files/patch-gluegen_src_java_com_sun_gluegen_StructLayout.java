--- gluegen/src/java/com/sun/gluegen/StructLayout.java.orig	2008-02-23 06:46:44.000000000 +1100
+++ gluegen/src/java/com/sun/gluegen/StructLayout.java	2008-06-09 08:40:19.000000000 +1000
@@ -140,6 +140,7 @@
                (os.startsWith("mac os") && cpu.equals("i386")) ||
                (os.startsWith("mac os") && cpu.equals("x86_64")) ||
                (os.startsWith("freebsd") && cpu.equals("i386")) ||
+               (os.startsWith("freebsd") && cpu.equals("amd64")) ||
                (os.startsWith("hp-ux") && cpu.equals("pa_risc2.0"))
                ) {
       // FIXME: make struct alignment configurable? May need to change
