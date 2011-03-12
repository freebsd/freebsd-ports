# New ports collection makefile for:    raw images library
# Date created:         26 Apr 2008
# Whom:                 osa
#
# $FreeBSD$
#

PORTNAME=	libraw
PORTVERSION=	0.13.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.su/data/
DISTNAME=	LibRaw-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for manipulating raw images

LICENSE=	LGPL21 CDDL
LICENSE_COMB=	dual

OPTIONS=	DEMOSAIC_PACK_GPL2	"Enable demosaic pack GPL2" off \
		DEMOSAIC_PACK_GPL3	"Enable demosaic pack GPL3" off \
		LCMS			"Build with lcms" on \
		OPTIMIZED_CFLAGS	"Enable optimization" off

.include <bsd.port.pre.mk>

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg
USE_PKGCONFIG=  yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=--program-prefix=${PREFIX} --disable-examples
CFLAGS+=	-fPIC

.if defined(WITH_OPTIMIZED_CFLAGS)
.if ${ARCH} == "i386"
CFLAGS+=	-O3
.endif
.endif

.if defined(WITH_LCMS)
LIB_DEPENDS+=	lcms2.2:${PORTSDIR}/graphics/lcms2
CONFIGURE_ARGS+=--enable-lcms
.else
CONFIGURE_ARGS+=--disable-lcms
.endif

.if defined(WITH_DEMOSAIC_PACK_GPL2)
LICENSE+=	GPLv2
DISTFILES+=	LibRaw-demosaic-pack-GPL2-${PORTVERSION}.tar.gz
CONFIGURE_ARGS+=--enable-demosaic-pack-gpl2=../LibRaw-demosaic-pack-GPL2-${PORTVERSION}
.else
CONFIGURE_ARGS+=--disable-demosaic-pack-gpl2
.endif

.if defined(WITH_DEMOSAIC_PACK_GPL3)
LICENSE+=	GPLv3
DISTFILES+=	LibRaw-demosaic-pack-GPL3-${PORTVERSION}.tar.gz
CONFIGURE_ARGS+=--enable-demosaic-pack-gpl3=../LibRaw-demosaic-pack-GPL3-${PORTVERSION}
.else
CONFIGURE_ARGS+=--disable-demosaic-pack-gpl3
.endif

PORTDOCS=	API-C-eng.html API-C-rus.html API-CXX-eng.html API-CXX-rus.html \
		API-datastruct-eng.html API-datastruct-rus.html API-notes-eng.html \
		API-notes-rus.html API-overview-eng.html API-overview-rus.html \
		Install-LibRaw-eng.html Install-LibRaw-rus.html \
		Samples-LibRaw-eng.html Samples-LibRaw-rus.html \
		Why-LibRaw-eng.html Why-LibRaw-rus.html corner-scheme.png \
		index-eng.html index-rus.html index.html

PORTEXAMPLES=	4channels.cpp dcraw_emu.cpp dcraw_half.c half_mt.c mem_image.cpp \
		raw-identify.cpp simple_dcraw.cpp unprocessed_raw.cpp

do-install:
	@${MKDIR} ${PREFIX}/include/libraw

.for f in libraw.h libraw_alloc.h libraw_const.h libraw_datastream.h \
	libraw_internal.h libraw_types.h libraw_version.h
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} ${PREFIX}/include/libraw
.endfor
.for f in libraw.a libraw_r.a
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib
.endfor

.for f in libraw.so.2 libraw_r.so.2
	@${INSTALL_DATA} ${WRKSRC}/lib/.libs/${f} ${PREFIX}/lib
.endfor
.for f in libraw libraw_r
	@ cd ${PREFIX}/lib ; ${LN} -sf ${f}.so.0 ${f}.so
.endfor

.for f in libraw.pc libraw_r.pc
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/libdata/pkgconfig
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
