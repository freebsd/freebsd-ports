# $FreeBSD$

all:
	gmake -f Makefile.qmc2 EMULATOR=SDLMAME
	mkdir bin
	mv qmc2-sdlmame bin/
	gmake -f Makefile.qmc2 EMULATOR=SDLMAME clean
	gmake -f Makefile.qmc2 EMULATOR=SDLMESS
	mv qmc2-sdlmess bin/

