# $FreeBSD$

LIB=		flash
SHLIB_MAJOR?=	0
SHLIB_MINOR?=	4
CXXFLAGS+=	-fno-rtti -DXP_UNIX	\
		-I${LOCALBASE}/include	\
		-DCHECK_TEXT_PLAIN
LDADD=		-lz \
		-L${LOCALBASE}/lib -ljpeg
SRCS=		adpcm.cc bitmap.cc button.cc character.cc cxform.cc \
		displaylist.cc flash.cc font.cc graphic.cc graphic16.cc \
		graphic24.cc graphic32.cc matrix.cc movie.cc \
		program.cc script.cc shape.cc sound.cc \
		sprite.cc sqrt.cc text.cc
INCS=		flash.h
NOMAN=		YES
LIBDIR=		${LOCALBASE}/lib
INCSDIR=	${LOCALBASE}/include
INCDIR=		${INCSDIR}		# for pre-bsd.incs.mk API

.include <bsd.lib.mk>
