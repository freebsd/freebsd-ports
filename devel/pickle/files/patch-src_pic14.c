--- src/pic14.c.orig	2026-05-14 09:57:55 UTC
+++ src/pic14.c
@@ -1240,21 +1240,6 @@ pic14_row_erase_program_memory(uint32_t t)
 	io_usleep(t);
 }
 
-/*
- * ROW ERASE MEMORY (NVM)
- *  RETURN (PC)
- *
- * X00101 = 0x05
- *
- * DS40001738C-page 7   16F18313
- */
-static inline void
-pic14_row_erase_memory(uint32_t t)
-{
-	io_program_out(0x05, 6);
-	io_usleep(t);
-}
-
 /*****************************************************************************
  *
  * Compound functions
@@ -1491,7 +1476,7 @@ pic14_row_erase(uint32_t row, uint32_t nrows)
 	if (row == PIC_ERASE_CONFIG) {
 		for (uint32_t i = 0; i < PIC14_CONFIG_MAX; ++i)
 			pic14_conf.config[i] = 0x3FFF;
-		
+
 		/* ERASE CONFIG */
 		pic14_write_config();
 		return;
@@ -1788,7 +1773,7 @@ pic14_write_word(uint16_t region)
 			/*			END PROGRAMMING   */
 			pic14_end_programming_001110(PIC14_TDISCHARGE_DEFAULT);
 			break;
-			
+
 	case DS41284E:	/* PIC12F615/617	BEGIN PROGRAMMING */
 	case DS41191C:	/* PIC12F629/675	BEGIN PROGRAMMING */
 			/* PIC16F630/676	BEGIN PROGRAMMING */
@@ -2506,19 +2491,19 @@ pic14_dumpconfig_12f675(uint16_t config)
 	case 2: printf("\t[BG1:BG0] 10\n"); break;
 	case 3: printf("\t[BG1:BG0] 11\n"); break;
 	}
-	
+
 	w = config & 0x100;
 	if (w)
 		printf("\n[CPD] Data memory code protection off\n");
 	else
 		printf("\n[CPD] Data memory code protection on\n");
-	
+
 	w = config & 0x80;
 	if (w)
 		printf("\n[CP] Program memory code protection off\n");
 	else
 		printf("\n[CP] Program memory code protection on\n");
-	
+
 	w = config & 0x40;
 	if (w)
 		printf("\n[BODEN] Brown-out detect reset enabled\n");
@@ -2576,7 +2561,7 @@ pic14_dumpconfig_16f877a(uint16_t config)
 		printf("\n[DEBUG] In circuit debugger off\n");
 	else
 		printf("\n[DEBUG] In circuit debugger on\n");
-	
+
 	w = (config & 0x0600) >> 9;
 	printf("\nWrite protection:\n");
 	switch (w) {
@@ -2794,7 +2779,7 @@ pic14_dumpconfig_12f683(uint16_t config)
 		printf("\n[FCMEN] Fail-safe clock monitor enabled\n");
 	else
 		printf("\n[FCMEN] Fail-safe clock monitor disabled\n");
-	
+
 	w = config & 0x0300;
 	printf("\nBrown-out reset selection:\n");
 	switch (w) {
@@ -2809,13 +2794,13 @@ pic14_dumpconfig_12f683(uint16_t config)
 		printf("\n[CPD] Data memory code protection off\n");
 	else
 		printf("\n[CPD] Data memory code protection on\n");
-	
+
 	w = config & 0x0040;
 	if (w)
 		printf("\n[CP] Program memory code protection off\n");
 	else
 		printf("\n[CP] Program memory code protection on\n");
-	
+
 	w = config & 0x0020;
 	if (w)
 		printf("\n[MCLRE] MCLR enabled\n");
@@ -2855,7 +2840,7 @@ pic14_dumpconfig_16f886(uint16_t config1, uint16_t con
 pic14_dumpconfig_16f886(uint16_t config1, uint16_t config2)
 {
 	uint16_t w;
-	
+
 	w = config1 & 0x2000;
 	if (w)
 		printf("\n[DEBUG] In circuit debugger off\n");
@@ -2873,13 +2858,13 @@ pic14_dumpconfig_16f886(uint16_t config1, uint16_t con
 		printf("\n[FCMEN] Fail-safe clock monitor enabled\n");
 	else
 		printf("\n[FCMEN] Fail-safe clock monitor disabled\n");
-	
+
 	w = config1 & 0x0400;
 	if (w)
 		printf("\n[IESO] Internal/external switch over mode enabled\n");
 	else
 		printf("\n[IESO] Internal/external switch over mode disabled\n");
-	
+
 	w = config1 & 0x0300;
 	printf("\nBrown-out reset selection:\n");
 	switch (w) {
@@ -2934,7 +2919,7 @@ pic14_dumpconfig_16f886(uint16_t config1, uint16_t con
 
 	w = (config2 & 0x0006) >> 1;
 	printf("\n[WRT1:WRT0] Write protection: 0x%02X\n", w);
-	
+
 	w = config2 & 0x0001;
 	if (w)
 		printf("\n[BOR4V] Brown-out reset set to 4.0V\n");
@@ -3058,7 +3043,7 @@ pic14_dumpdevice(void)
 
 	/* Enhanced 14-bit: Extended address = 0x0001 (CONFIG: 0x8000) */
 	pic_dumpaddr(pic14_map[pic14_index].configaddr << 1, 1);
-	
+
 	/* USERID */
 	for (i = 0; i < 4; ++i)
 		pic_dumpword16(pic14_map[pic14_index].configaddr + i, pic14_conf.userid[i]);
