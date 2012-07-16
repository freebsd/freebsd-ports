# New ports collection makefile for:	raw images library
# Date created:				26 Apr 2008
# Whom:					Sergey A. Osokin <osa@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libraw
PORTVERSION=	0.14.7
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.su/data/
DISTNAME=	LibRaw-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for manipulating raw images

LICENSE=	LGPL21 CDDL
LICENSE_COMB=	dual

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-examples --disable-jasper
CFLAGS+=	-fPIC

OPTIONS_DEFINE=	DEMOSAIC_PACK_GPL2 DEMOSAIC_PACK_GPL3 LCMS2 OPTIMIZED_CFLAGS OPENMP
OPTIONS_DEFAULT=	LCMS2

DEMOSAIC_PACK_GPL2_DESC=	Enable GPLv2 demosaic pack
DEMOSAIC_PACK_GPL3_DESC=	Enable GPLv3 demosaic pack
OPTIMIZED_CFLAGS_DESC=		Enable optimizations (on x86)
OPENMP_DESC=			Enable OpenMP (implies GCC 4.6+)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
.if ${ARCH} == "i386"
CFLAGS+=	-O3
.endif
.endif

.if ${PORT_OPTIONS:MOPENMP}
USE_GCC=	4.6+
CONFIGURE_ARGS+=--enable-openmp
.else
CONFIGURE_ARGS+=--disable-openmp
.endif

.if ${PORT_OPTIONS:MLCMS2}
LIB_DEPENDS+=	lcms2.2:${PORTSDIR}/graphics/lcms2
CONFIGURE_ARGS+=--enable-lcms
.else
CONFIGURE_ARGS+=--disable-lcms
.endif

.if ${PORT_OPTIONS:MDEMOSAIC_PACK_GPL2}
LICENSE+=	GPLv2
DISTFILES+=	LibRaw-demosaic-pack-GPL2-${PORTVERSION}.tar.gz
CONFIGURE_ARGS+=--enable-demosaic-pack-gpl2=../LibRaw-demosaic-pack-GPL2-${PORTVERSION}
.else
CONFIGURE_ARGS+=--disable-demosaic-pack-gpl2
.endif

.if ${PORT_OPTIONS:MDEMOSAIC_PACK_GPL3}
LICENSE+=	GPLv3
DISTFILES+=	LibRaw-demosaic-pack-GPL3-${PORTVERSION}.tar.gz
CONFIGURE_ARGS+=--enable-demosaic-pack-gpl3=../LibRaw-demosaic-pack-GPL3-${PORTVERSION}
.else
CONFIGURE_ARGS+=--disable-demosaic-pack-gpl3
.endif

PORTDOCS=	API-C-eng.html API-C-rus.html API-CXX-eng.html \
		API-CXX-rus.html API-datastruct-eng.html \
		API-datastruct-rus.html API-notes-eng.html API-notes-rus.html \
		API-overview-eng.html API-overview-rus.html \
		Install-LibRaw-eng.html Install-LibRaw-rus.html \
		Samples-LibRaw-eng.html Samples-LibRaw-rus.html \
		Why-LibRaw-eng.html Why-LibRaw-rus.html \
		index-eng.html index-rus.html index.html

PORTEXAMPLES=	Makefile README-samples.rus 4channels.cpp dcraw_emu.cpp \
		dcraw_half.c half_mt.c mem_image.cpp \
		multirender_test.cpp postprocessing_benchmark.cpp \
		raw-identify.cpp simple_dcraw.cpp unprocessed_raw.cpp

do-install:
	@${MKDIR} ${PREFIX}/include/libraw

.for f in libraw.h libraw_alloc.h libraw_const.h libraw_datastream.h \
	libraw_internal.h libraw_types.h libraw_version.h
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} ${PREFIX}/include/libraw
.endfor
.for f in libraw.a libraw_r.a libraw.so.5 libraw_r.so.5
	${INSTALL_DATA} ${WRKSRC}/lib/.libs/${f} ${PREFIX}/lib
.endfor
.for f in libraw libraw_r
	@cd ${PREFIX}/lib ; ${LN} -sf ${f}.so.5 ${f}.so
.endfor

.for f in libraw.pc libraw_r.pc
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/libdata/pkgconfig
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/samples/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
