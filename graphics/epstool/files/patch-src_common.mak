--- src/common.mak.orig	2024-02-06 11:23:13 UTC
+++ src/common.mak
@@ -77,7 +77,7 @@ plapis_h=$(SRC)plapis.h
 plapis_h=$(SRC)plapis.h
 
 
-all: $(BEGIN) $(TARGET)
+all: $(BEGIN) .WAIT $(TARGET)
 
 $(OD)calloc$(OBJ): $(SRC)calloc.c $(common_h)
 	$(COMP) $(FOO)calloc$(OBJ) $(CO) $(SRC)calloc.c
