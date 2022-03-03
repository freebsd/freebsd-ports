# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>

PORTNAME=	furnace
PORTVERSION=	0.5.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://sid.ethz.ch/debian/furnace/ \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_${PORTVERSION}+git20220302+ds.orig

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Chiptune tracker compatible with DefleMask modules (.dmf)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libfmt.so:devel/libfmt \
		librtmidi.so:audio/rtmidi \
		libsndfile.so:audio/libsndfile

USES=		cmake pkgconfig sdl tar:xz
USE_SDL=	sdl2

CMAKE_ARGS+=	-DBUILD_GUI:BOOL=ON \
		-DSYSTEM_FMT:BOOL=ON \
		-DSYSTEM_LIBSNDFILE:BOOL=ON \
		-DSYSTEM_RTMIDI=ON \
		-DSYSTEM_SDL2:BOOL=ON \
		-DSYSTEM_ZLIB:BOOL=ON

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}+git20220302+ds

OPTIONS_DEFINE=	DOCS JACK

JACK_LIB_DEPENDS=	libjack.so:audio/jack
JACK_CMAKE_OFF=		-DWITH_JACK:BOOL=OFF

post-install:
	${INSTALL_DATA} \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/1024x1024/apps/furnace.png \
		${STAGEDIR}${PREFIX}/share/icons/

.include <bsd.port.mk>
