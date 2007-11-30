--- ./src/mess/mess.mak.orig	Tue Oct 16 11:24:59 2007
+++ ./src/mess/mess.mak	Thu Nov 29 15:25:32 2007
@@ -13,7 +13,7 @@
 EMUSRC = $(SRC)/emu
 EMUOBJ = $(OBJ)/emu
 
-EMU_AUDIO = $(ENUOBJ)/audio
+EMU_AUDIO = $(EMUOBJ)/audio
 EMU_MACHINE = $(EMUOBJ)/machine
 EMU_VIDEO = $(EMUOBJ)/video
 MAME_AUDIO = $(MAMEOBJ)/audio
