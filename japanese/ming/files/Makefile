# $FreeBSD$

.PATH: ${.CURDIR}/actioncompiler ${.CURDIR}/blocks

LIB=		ming
SHLIB_MAJOR?=	3
SHLIB_MINOR?=	0
CFLAGS+=	-I${.CURDIR}/actioncompiler -I${.CURDIR}/blocks -I${LOCALBASE}/include
LDADD=		-lm
SRCS=		blocklist.c \
		displaylist.c \
		fill.c \
		ming.c \
		movie.c \
		movieclip.c \
		position.c \
		shape_cubic.c \
		shape_util.c \
		text_util.c \
		assembler.c \
		compile.c \
		compileaction.c \
		lex.swf4.c \
		lex.swf5.c \
		swf4compiler.tab.c \
		swf5compiler.tab.c \
		action.c \
		bitmap.c \
		block.c \
		browserfont.c \
		button.c \
		character.c \
		cxform.c \
		dbl.c \
		error.c \
		fillstyle.c \
		font.c \
		fontinfo.c \
		gradient.c \
		input.c \
		jpeg.c \
		linestyle.c \
		loadfont.c \
		matrix.c \
		method.c \
		morph.c \
		mp3.c \
		output.c \
		outputblock.c \
		placeobject.c \
		rect.c \
		shape.c \
		soundstream.c \
		sprite.c \
		text.c \
		textfield.c
INCSGROUPS=	INCS BLKS
INCS=		blocklist.h \
		blocktypes.h \
		displaylist.h \
		fill.h \
		libming.h \
		../ming.h \
		../mingpp.h \
		movie.h \
		movieclip.h \
		position.h \
		shape_cubic.h \
		shape_util.h \
		text_util.h

NOMAN=		YES
LIBDIR=		${LOCALBASE}/lib
INCSDIR=	${LOCALBASE}/include/ming

BLKS=		block.h cxform.h \
		error.h exports.h \
		input.h matrix.h \
		outputblock.h placeobject.h \
		sound.h sprite.h \
		swf.h blocktypes.h \
		character.h libswf.h \
		method.h output.h \
		rect.h
BLKS:=		${BLKS:S;^;${.CURDIR}/blocks/;}
BLKSDIR=	${INCSDIR}/blocks

.include <bsd.lib.mk>

# For pre-bsd.incs.mk API
.if defined(INCOWN)
INCDIR=		${INCSDIR}
beforeinstall:
	${INSTALL} -C -o ${INCOWN} -g ${INCGRP} -m ${INCMODE} \
		${.CURDIR}/blocks/block.h ${.CURDIR}/blocks/cxform.h \
		${.CURDIR}/blocks/error.h ${.CURDIR}/blocks/exports.h \
		${.CURDIR}/blocks/input.h ${.CURDIR}/blocks/matrix.h \
		${.CURDIR}/blocks/outputblock.h ${.CURDIR}/blocks/placeobject.h \
		${.CURDIR}/blocks/sound.h ${.CURDIR}/blocks/sprite.h \
		${.CURDIR}/blocks/swf.h ${.CURDIR}/blocks/blocktypes.h \
		${.CURDIR}/blocks/character.h ${.CURDIR}/blocks/libswf.h \
		${.CURDIR}/blocks/method.h ${.CURDIR}/blocks/output.h \
		${.CURDIR}/blocks/rect.h  ${INCDIR}/blocks/
.endif

dynamic: lib${LIB}.so

static: lib${LIB}.a

