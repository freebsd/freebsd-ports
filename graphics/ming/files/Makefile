# $FreeBSD$

LIB=		ming
SHLIB_MAJOR?=	0
SHLIB_MINOR?=	0
CFLAGS+=	-I${.CURDIR}/actioncompiler -I${.CURDIR}/blocks -I${LOCALBASE}/include
LDADD=		-lm
SRCS=		blocklist.c \
		displaylist.c \
		movie.c \
		movieclip.c \
		position.c \
		actioncompiler/compile.c \
		actioncompiler/compileaction.c \
		actioncompiler/compiler.tab.c \
		actioncompiler/lex.yy.c \
		blocks/action.c \
		blocks/block.c \
		blocks/browserfont.c \
		blocks/button.c \
		blocks/character.c \
		blocks/cxform.c \
		blocks/dbl.c \
		blocks/fill.c \
		blocks/font.c \
		blocks/fontinfo.c \
		blocks/jpeg.c \
		blocks/loadfont.c \
		blocks/matrix.c \
		blocks/method.c \
		blocks/mp3.c \
		blocks/output.c \
		blocks/outputblock.c \
		blocks/rect.c \
		blocks/shape.c \
		blocks/soundstream.c \
		blocks/sprite.c \
		blocks/text.c \
		blocks/textfield.c
INCS=		blocktypes.h \
		ming.h \
		swf.h
NOMAN=		YES
LIBDIR=		${LOCALBASE}/lib
INCDIR=		${LOCALBASE}/include/ming

.include <bsd.lib.mk>
