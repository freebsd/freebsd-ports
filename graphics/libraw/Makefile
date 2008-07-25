# New ports collection makefile for:    raw images library
# Date created:         26 Apr 2008
# Whom:                 osa
#
# $FreeBSD$
#

PORTNAME=	libraw
PORTVERSION=	0.5.3
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.su/data/
DISTNAME=	LibRaw-${PORTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for manipulating raw images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms

MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

USE_LDCONFIG=	yes

PORTDOCS=	API-C-eng.html API-C-rus.html API-CXX-eng.html API-CXX-rus.html \
		API-datastruct-eng.html API-datastruct-rus.html API-notes-eng.html \
		API-notes-rus.html API-overview-eng.html API-overview-rus.html \
		Install-LibRaw-eng.html Install-LibRaw-rus.html Samples-LibRaw-eng.html \
		Samples-LibRaw-rus.html Why-LibRaw-eng.html Why-LibRaw-rus.html \
		index-eng.html index-rus.html index.html

PORTEXAMPLES=	dcraw_emu.cpp dcraw_half.c half_mt.c identify.cpp simple_dcraw.cpp

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O4
.else
pre-everything::
	@${ECHO_CMD} ""
	@${ECHO_CMD} "The following options are available:"
	@${ECHO_CMD} "	WITH_OPTIMIZED_CFLAGS	- build port with optimization support"
	@${ECHO_CMD} ""
.endif
.endif

do-install:
	@${MKDIR} ${PREFIX}/include/libraw

.for f in libraw.h libraw_alloc.h libraw_const.h libraw_internal.h libraw_io.h libraw_types.h
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} ${PREFIX}/include/libraw
.endfor
.for f in libraw.a libraw.so.0 libraw_r.a libraw_r.so.0
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib
.endfor
.for f in libraw libraw_r
	@ cd ${PREFIX}/lib ; ${LN} -sf ${f}.so.0 ${f}.so
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/samples/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
