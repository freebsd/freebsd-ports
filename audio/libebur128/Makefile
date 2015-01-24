# Created by: gahr
# $FreeBSD$

PORTNAME=	libebur128
PORTVERSION=	1.0.1
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the EBU R128 loudness standard

LICENSE=	MIT

LIB_DEPENDS=	libspeexdsp.so:${PORTSDIR}/audio/speexdsp

USES=		cmake:outsource pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj
GH_TAGNAME=	v${PORTVERSION}
GH_COMMIT=	1214547

PLIST_SUB+=	VER1=${PORTVERSION:R:R} \
		VER3=${PORTVERSION}

.include <bsd.port.mk>
