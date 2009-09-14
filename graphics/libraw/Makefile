# New ports collection makefile for:    raw images library
# Date created:         26 Apr 2008
# Whom:                 osa
#
# $FreeBSD$
#

PORTNAME=	libraw
PORTVERSION=	0.8.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.libraw.su/data/
DISTNAME=	LibRaw-${PORTVERSION}

MAINTAINER=	osa@FreeBSD.org
COMMENT=	Library for manipulating raw images

OPTIONS=	OPTIMIZED_CFLAGS "Enable optimization" off \
		SHARED_LIBS "Install shared libraries" off

.include <bsd.port.pre.mk>

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		lcms.1:${PORTSDIR}/graphics/lcms

.if defined(WITH_OPTIMIZED_CFLAGS)
.if ${ARCH} == "i386"
CFLAGS+=	-O3
.endif
.endif

MAKE_ENV+=	PTHREAD_CFLAGS=${PTHREAD_CFLAGS} PTHREAD_LIBS=${PTHREAD_LIBS}

.if defined(WITH_SHARED_LIBS)
USE_LDCONFIG=	yes
PLIST_SUB+=	SHAREDLIBS=""
.else
PLIST_SUB+=	SHAREDLIBS="@comment "
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

post-patch:
	@${REINPLACE_CMD} -i.bak -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|gcc|${CC}|' \
		-e 's|g++|${CXX}|' \
		${WRKSRC}/Makefile

do-install:
	@${MKDIR} ${PREFIX}/include/libraw

.for f in libraw.h libraw_alloc.h libraw_const.h libraw_datastream.h \
	libraw_internal.h libraw_types.h libraw_version.h
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}/${f} ${PREFIX}/include/libraw
.endfor
.for f in libraw.a libraw_r.a
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib
.endfor

.if defined(WITH_SHARED_LIBS)
.for f in libraw.so.0 libraw_r.so.0
	@${INSTALL_DATA} ${WRKSRC}/lib/${f} ${PREFIX}/lib
.endfor
.for f in libraw libraw_r
	@ cd ${PREFIX}/lib ; ${LN} -sf ${f}.so.0 ${f}.so
.endfor
.endif

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/doc/,} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S,^,${WRKSRC}/samples/,} ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
