# New ports collection makefile for:	iulib
# Date created:		2009-05-20
# Whom:			Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	iulib
PORTVERSION=	0.3
CATEGORIES=	graphics
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	A library of image understanding-related algorithms

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/iulib

OPTIONS=	SDL "Enable SDL" off \
		VIDIO "Enable Video Input/Output (using ffmpeg)" off

MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool:15 aclocal:110 automake:110 autoconf:262
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I${LOCALBASE}/share/aclocal
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.pre.mk>

.if !defined(WITH_SDL)
CONFIGURE_ARGS+=--without-SDL
.else
USE_SDL=	sdl
.endif

.if !defined(WITH_VIDIO)
PLIST_SUB+=	VIDIO="@comment "
.else
LIB_DEPENDS+=	avcodec.1:${PORTSDIR}/multimedia/ffmpeg
PLIST_SUB+=	VIDIO=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/tiff/s/^/#/' ${WRKSRC}/configure.ac
.if !defined(WITH_VIDIO)
	@${REINPLACE_CMD} -e 's/novidio, 0/novidio, 1/' ${WRKSRC}/configure.ac
.endif

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} \
	  && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE} --automake)

run-autotools: run-autotools-aclocal run-autotools-automake run-autotools-autoconf

.include <bsd.port.post.mk>
