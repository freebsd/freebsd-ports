# New ports collection makefile for:	OCRopus
# Date created:		2009-05-20
# Whom:			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ocropus
PORTVERSION=	0.3.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	The OCRopus(tm) open source document analysis and OCR system

BUILD_DEPENDS=	${LOCALBASE}/lib/libtesseract_full.a:${PORTSDIR}/graphics/tesseract
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		iulib.0:${PORTSDIR}/graphics/iulib

WRKSRC=		${WRKDIR}/ocropus-0.3

OPTIONS=	SDL "Enable SDL for graphical debugging" off \
		LEPTONICA "Enable Leptonica image analysis" off

MAKE_JOBS_UNSAFE=	yes
USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262
USE_GMAKE=	yes
CONFIGURE_ARGS=	--without-fst
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if !defined(WITH_SDL)
CONFIGURE_ARGS+=--without-SDL
.else
USE_SDL=	sdl
.endif

.if !defined(WITH_LEPTONICA)
CONFIGURE_ARGS+=--without-leptonica
PLIST_SUB+=	LEPTONICA="@comment "
.else
LIB_DEPENDS+=	lept.0:${PORTSDIR}/graphics/leptonlib
PLIST_SUB+=	LEPTONICA=""
.endif

run-autotools: run-autotools-aclocal run-autotools-automake run-autotools-autoconf

.include <bsd.port.post.mk>
