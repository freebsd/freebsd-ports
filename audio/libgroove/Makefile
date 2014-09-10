# Created by: gahr
# $FreeBSD$

PORTNAME=	libgroove
PORTVERSION=	4.1.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Audio dispatching library

LICENSE=	MIT

LIB_DEPENDS=	libavcodec.so:${PORTSDIR}/multimedia/libav \
    		libchromaprint.so:${PORTSDIR}/audio/chromaprint \
		libebur128.so:${PORTSDIR}/audio/libebur128 \
		libspeexdsp.so:${PORTSDIR}/audio/speex \
		libSDL2.so:${PORTSDIR}/devel/sdl20

USES=		cmake:outsource
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	andrewrk
GH_COMMIT=	1b90d6c

PLIST_SUB+=	VER1=${PORTVERSION:R:R} \
    		VER3=${PORTVERSION}

.include <bsd.port.mk>
