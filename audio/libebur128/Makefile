# Created by: gahr
# $FreeBSD$

PORTNAME=	libebur128
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the EBU R128 loudness standard

LICENSE=	MIT

LIB_DEPENDS=	libspeexdsp.so:${PORTSDIR}/audio/speexdsp

USES=		cmake:outsource pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj

PLIST_SUB+=	VER1=${PORTVERSION:R:R} \
		VER3=${PORTVERSION}

.include <bsd.port.mk>
