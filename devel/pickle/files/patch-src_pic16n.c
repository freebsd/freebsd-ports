--- src/pic16n.c.orig	2026-05-14 09:55:47 UTC
+++ src/pic16n.c
@@ -373,22 +373,6 @@ pic16n_read_data_from_nvm(uint8_t j /* 0 || 1 */)
 }
 
 /*
- * INCREMENT ADDRESS
- *  0xF8 PC = PC + 2 CODE
- *  0xF8 PC = PC + 1 DATA
- *
- * DS40001772B-page 10
- * DS40001874F-page 10
- * DS40002079D-page 13
- */
-static inline void
-pic16n_increment_address(void)
-{
-	io_program_out(0xF8, 8);
-	/* TDLY 1us */
-}
-
-/*
  * LOAD PC ADDRESS
  *  0x80 PC = address
  *
@@ -423,36 +407,6 @@ pic16n_begin_internally_timed_programming(uint32_t t)
 }
 
 /*
- * BEGIN EXTERNALLY TIMED PROGRAMMING
- *  0xC0
- *
- * DS40001772B-page 12
- * DS40001772B TPEXT(2.1ms PROGRAM) (NOT CONFIG)
- */
-static inline void
-pic16n_begin_externally_timed_programming(uint32_t t)
-{
-	io_program_out(0xC0, 8);
-	/* TPEXT */
-	io_usleep(t);
-}
-
-/*
- * END EXTERNALLY TIMED PROGRAMMING
- *  0x82
- *
- * DS40001772B-page 12
- * DS40001772B TDIS(300us PROGRAM)
- */
-static inline void
-pic16n_end_externally_timed_programming(uint32_t t)
-{
-	io_program_out(0x82, 8);
-	/* TDIS */
-	io_usleep(t);
-}
-
-/*
  * PROGRAM DATA COMMAND
  *  0xC0 PC = PC
  *  0xE0 PC = PC + 2
@@ -518,20 +472,6 @@ pic16n_bulk_erase_memory_Q43(uint32_t t)
 	io_usleep(t);
 }
 
-/*
- * ROW ERASE MEMORY (PRELOAD PC)
- *  0xF0
- *
- * DS40001772B-page 12
- * DS40001772B TERAR(2.8ms)
- */
-static inline void
-pic16n_row_erase_memory(uint32_t t)
-{
-	io_program_out(0xF0, 8);
-	io_usleep(t);
-}
-
 /*****************************************************************************
  *
  * Compound functions
@@ -1360,7 +1300,7 @@ pic16n_dumpdeviceid(void)
 		pic16n_conf.revisionid,
 		(pic16n_conf.revisionid >> PIC16N_MAJOR_SHIFT) & PIC16N_REV_MASK,
 		pic16n_conf.revisionid & PIC16N_REV_MASK);
-	printf("[3FFFFE] [DEVICEID] %04X %s\n", pic16n_conf.deviceid,	
+	printf("[3FFFFE] [DEVICEID] %04X %s\n", pic16n_conf.deviceid,
 		pic16n_map[pic16n_index].devicename);
 }
 
