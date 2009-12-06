--- a/pc-bios/optionrom/multiboot.S
+++ b/pc-bios/optionrom/multiboot.S
@@ -113,7 +113,10 @@ mmap_loop:
 	/* entry size (mmap struct) & max buffer size (int15) */
 	movl		$20, %ecx
 	/* store entry size */
+	/* old as(1) doesn't like this insn so emit the bytes instead:
 	movl		%ecx, %es:-4(%edi)
+	*/
+	.dc.b		0x26,0x67,0x66,0x89,0x4f,0xfc
 	/* e820 */
 	movl		$0x0000e820, %eax
 	/* 'SMAP' magic */
-- 
1.6.5.2

