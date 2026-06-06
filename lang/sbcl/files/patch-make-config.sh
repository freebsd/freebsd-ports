--- make-config.sh.orig
+++ make-config.sh
@@ -765,6 +765,16 @@
     fi
     ;;
   ppc64)
+    # The ppc64 C calling convention is either ELFv1, which passes function
+    # pointers as 3-word descriptors, or ELFv2, which branches to the entry
+    # address directly.  This is a property of the toolchain, independent of
+    # endianness (ppc64le is always ELFv2; ppc64 big-endian may be either), so
+    # ask the C compiler which ABI it targets via its _CALL_ELF predefine
+    # (2 = ELFv2, 1 or undefined = ELFv1) and add :ppc64-elfv1 for the
+    # descriptor ABI.
+    if [ "`echo | ${CC:-cc} -E -dM - 2>/dev/null | grep -w _CALL_ELF | awk '{print $3}'`" != 2 ]; then
+        printf ' :ppc64-elfv1' >> $ltf
+    fi
    ;;
   riscv)
     if [ "$xlen" = "64" ]; then
