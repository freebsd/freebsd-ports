--- arch/x86/tools/relocs.c.orig	2016-07-28 10:57:47 UTC
+++ arch/x86/tools/relocs.c
@@ -54,12 +54,12 @@ static const char * const sym_regex_kern
 	[S_REL] =
 	"^(__init_(begin|end)|"
 	"__x86_cpu_dev_(start|end)|"
-	"(__parainstructions|__alt_instructions)(|_end)|"
-	"(__iommu_table|__apicdrivers|__smp_locks)(|_end)|"
+	"((__parainstructions|__alt_instructions)_end|(__parainstructions|__alt_instructions))|"
+	"((__iommu_table|__apicdrivers|__smp_lock)_end|(__iommu_table|__apicdrivers|__smp_lock))|"
 	"__(start|end)_pci_.*|"
 	"__(start|end)_builtin_fw|"
-	"__(start|stop)___ksymtab(|_gpl|_unused|_unused_gpl|_gpl_future)|"
-	"__(start|stop)___kcrctab(|_gpl|_unused|_unused_gpl|_gpl_future)|"
+	"(__(start|stop)___ksymtab|__(start|stop)___ksymtab(_gpl|_unused|_unused_gpl|_gpl_future))|"
+	"(__(start|stop)___kcrctab|__(start|stop)___kcrctab(_gpl|_unused|_unused_gpl|_gpl_future))|"
 	"__(start|stop)___param|"
 	"__(start|stop)___modver|"
 	"__(start|stop)___bug_table|"
