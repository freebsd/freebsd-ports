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
INCDIR=		${LOCALBASE}/include

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
