# New ports collection makefile for:	OCRopus
# Date created:		2009-05-20
# Whom:			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ocropus
PORTVERSION=	0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	The OCRopus(tm) open source document analysis and OCR system

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		iulib.0:${PORTSDIR}/graphics/iulib \
		gsl.13:${PORTSDIR}/math/gsl

WRKSRC=		${WRKDIR}/ocropus-0.4/ocropus

OPTIONS=	SDL "Enable SDL for graphical debugging" off \
		LEPTONICA "Enable Leptonica image analysis" off

MAKE_JOBS_UNSAFE=	yes
USE_PYTHON_BUILD=	yes
USE_AUTOTOOLS=	aclocal:110 automake:110 autoconf:262
USE_GMAKE=	yes
CONFIGURE_ARGS=	--without-fst --without-tesseract --with-iulib=${LOCALBASE}
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib
USE_GCC=	4.2+

.include <bsd.port.pre.mk>

.if !defined(WITH_SDL)
CONFIGURE_ARGS+=--without-SDL
.else
USE_SDL=	sdl
.endif

.if !defined(WITH_LEPTONICA)
CONFIGURE_ARGS+=--without-leptonica
.else
LIB_DEPENDS+=	lept.0:${PORTSDIR}/graphics/leptonlib
.endif

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} \
	  && ${SETENV} ${PYTHON_CMD} genAM.py >Makefile.am)

run-autotools: run-autotools-aclocal run-autotools-automake run-autotools-autoconf

run-autotools-autoconf:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${AUTOCONF} \
		${AUTOCONF_ARGS})
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|'\
		${WRKSRC}/configure

.include <bsd.port.post.mk>
