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

LIB_DEPENDS=	libspeexdsp.so:audio/speexdsp

DEPRECATED=		Duplicate port use `audio/codec2` instead
EXPIRATATION_DATE=	2016-12-03
CONFLICTS=		codec2-*
BROKEN_powerpc64=	Does not build

USE_LDCONFIG=	yes
USES=		cmake:outsource tar:xz

.include <bsd.port.mk>
