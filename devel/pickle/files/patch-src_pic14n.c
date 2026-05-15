--- src/pic14n.c.orig	2020-08-04 03:14:51 UTC
+++ src/pic14n.c
@@ -364,19 +364,6 @@ pic14n_read_data_from_nvm(uint8_t j /* 0 || 1 */)
 }
 
 /*
- * INCREMENT ADDRESS
- *  0xF8 PC = PC + 1
- *
- * DS40001753B-page 13
- */
-static inline void
-pic14n_increment_address(void)
-{
-	io_program_out(0xF8, 8);
-	/* TDLY 1us */
-}
-
-/*
  * LOAD PC ADDRESS
  *  0x80 PC = address
  *
@@ -409,38 +396,6 @@ pic14n_begin_internally_timed_programming(uint32_t t)
 	io_usleep(t);
 }
 
-/*
- * BEGIN EXTERNALLY TIMED PROGRAMMING
- *  0xC0
- *
- * DS40001753B-page 14
- *
- * DS40001753B TPEXT(2.8ms PROGRAM) (NOT CONFIG)
- */
-static inline void
-pic14n_begin_externally_timed_programming(uint32_t t)
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
- * DS40001753B-page 14
- *
- * DS40001753B TDIS(300us PROGRAM)
- */
-static inline void
-pic14n_end_externally_timed_programming(uint32_t t)
-{
-	io_program_out(0x82, 8);
-	/* TDIS */
-	io_usleep(t);
-}
-
 /*ERASE***********************************************************************/
 
 /*
@@ -459,21 +414,6 @@ pic14n_bulk_erase_memory(uint32_t t)
 pic14n_bulk_erase_memory(uint32_t t)
 {
 	io_program_out(0x18, 8);
-	io_usleep(t);
-}
-
-/*
- * ROW ERASE MEMORY (PRELOAD PC)
- *  0xF0
- *
- * DS40001753B-page 15
- *
- * DS40001753B TERAR(2.8ms)
- */
-static inline void
-pic14n_row_erase_memory(uint32_t t)
-{
-	io_program_out(0xF0, 8);
 	io_usleep(t);
 }
 
