# $FreeBSD$

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
		actioncompiler/assembler.c \
		actioncompiler/compile.c \
		actioncompiler/compileaction.c \
		actioncompiler/lex.swf4.c \
		actioncompiler/lex.swf5.c \
		actioncompiler/swf4compiler.tab.c \
		actioncompiler/swf5compiler.tab.c \
		blocks/action.c \
		blocks/bitmap.c \
		blocks/block.c \
		blocks/browserfont.c \
		blocks/button.c \
		blocks/character.c \
		blocks/cxform.c \
		blocks/dbl.c \
		blocks/error.c \
		blocks/fillstyle.c \
		blocks/font.c \
		blocks/fontinfo.c \
		blocks/gradient.c \
		blocks/input.c \
		blocks/jpeg.c \
		blocks/linestyle.c \
		blocks/loadfont.c \
		blocks/matrix.c \
		blocks/method.c \
		blocks/morph.c \
		blocks/mp3.c \
		blocks/output.c \
		blocks/outputblock.c \
		blocks/placeobject.c \
		blocks/rect.c \
		blocks/shape.c \
		blocks/soundstream.c \
		blocks/sprite.c \
		blocks/text.c \
		blocks/textfield.c
INCS=		blocklist.h \
		blocktypes.h \
		displaylist.h \
		fill.h \
		libming.h \
		ming.h \
		mingpp.h \
		movie.h \
		movieclip.h \
		position.h \
		shape_cubic.h \
		shape_util.h \
		text_util.h

NOMAN=		YES
LIBDIR=		${LOCALBASE}/lib
INCDIR=		${LOCALBASE}/include/ming

.include <bsd.lib.mk>

# For FreeBSD 3.x or older
.if !target(_includeinstall)
_includeinstall:
.if defined(INCS)
.for header in ${INCS}
        cd ${.CURDIR} && \
        ${INSTALL} -C -o ${INCOWN} -g ${INCGRP} -m ${INCMODE} \
                ${header} ${DESTDIR}${INCDIR}

.endfor
.endif

beforeinstall: _includeinstall
.endif

_includeinstall: pre-_includeinstall

pre-_includeinstall:
	mkdir -p ${DESTDIR}${INCDIR}/blocks

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

dynamic: lib${LIB}.so

static: lib${LIB}.a

