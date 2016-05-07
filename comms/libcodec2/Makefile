# Created by: Takefu <takefu@airport.fm>
# $FreeBSD$

PORTNAME=	libcodec2
PORTVERSION=	0.5
CATEGORIES=	comms hamradio
MASTER_SITES=	http://files.freedv.org/codec2/
DISTNAME=	codec2-${PORTVERSION}

MAINTAINER=	takefu@airport.fm
COMMENT=	Codec 2 speech codec

LICENSE=	LGPL21

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp

USE_LDCONFIG=	yes
USES=		cmake:outsource tar:xz

.include <bsd.port.mk>
