# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	ocropus
PORTVERSION=	0.4
PORTREVISION=	10
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	The OCRopus(tm) open source document analysis and OCR system

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff \
		iulib.0:${PORTSDIR}/graphics/iulib \
		gsl.16:${PORTSDIR}/math/gsl

WRKSRC=		${WRKDIR}/ocropus-0.4/ocropus

OPTIONS_DEFINE=	SDL LEPTONICA
SDL_DESC=	Enable SDL for graphical debugging
LEPTONICA_DESC=	Enable Leptonica image analysis

MAKE_JOBS_UNSAFE=	yes
USE_PYTHON_BUILD=	yes
USE_AUTOTOOLS=	aclocal automake autoconf
AUTOMAKE_ARGS=	--add-missing
USE_GMAKE=	yes
CONFIGURE_ARGS=	--without-fst --without-tesseract --with-iulib=${LOCALBASE}
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
.else
CONFIGURE_ARGS+=--without-SDL
.endif

.if ${PORT_OPTIONS:MLEPTONICA}
LIB_DEPENDS+=	lept:${PORTSDIR}/graphics/leptonica
.else
CONFIGURE_ARGS+=--without-leptonica
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

.include <bsd.port.mk>
