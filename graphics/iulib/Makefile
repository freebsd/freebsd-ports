# New ports collection makefile for:	iulib
# Date created:		2009-05-20
# Whom:			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	iulib
PORTVERSION=	0.4
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE
EXTRACT_SUFX=	.tgz

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	A library of image understanding-related algorithms

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

OPTIONS=	SDL "Enable SDL for graphical debugging" off \
		VIDIO "Enable Video Input/Output (using ffmpeg)" off

MAKE_JOBS_SAFE=	yes
USE_PYTHON_BUILD=	yes
USE_AUTOTOOLS=	libtool:15 aclocal:110 automake:110 autoconf:262
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I${LOCALBASE}/share/aclocal
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if !defined(WITH_SDL)
CONFIGURE_ARGS+=--without-SDL
PLIST_SUB+=	SDL="@comment "
.else
USE_SDL=	sdl gfx
PLIST_SUB+=	SDL=""
.endif

.if defined(WITH_VIDIO)
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
.else
post-patch:
	@${REINPLACE_CMD} -e 's/novidio, 0/novidio, 1/' ${WRKSRC}/configure.ac
.endif

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} \
	  && ${SETENV} ${PYTHON_CMD} genAM.py >Makefile.am \
	  && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake)

run-autotools: run-autotools-aclocal run-autotools-automake run-autotools-autoconf

.include <bsd.port.post.mk>
