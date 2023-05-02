PORTNAME=	libgroove
PORTVERSION=	4.3.0
PORTREVISION=	11
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio dispatching library
WWW=		https://github.com/andrewrk/libgroove

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Fails to build with FFmpeg 6 and very little activity upstream
EXPIRATION_DATE=2023-06-30

LIB_DEPENDS=	libavcodec.so.58:multimedia/ffmpeg4 \
		libchromaprint.so:audio/chromaprint \
		libebur128.so:audio/ebur128 \
		libspeexdsp.so:audio/speexdsp

USE_GITHUB=	yes
GH_ACCOUNT=	andrewrk

USES=		cmake sdl
USE_SDL=	sdl2
USE_LDCONFIG=	yes
CFLAGS+=	-Wno-error=deprecated-declarations # ffmpeg 3.1

PLIST_SUB+=	VER1=${PORTVERSION:R:R} \
		VER3=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${PATCH_WRKSRC}/cmake/FindLibAV.cmake

.include <bsd.port.mk>
