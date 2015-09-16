# Created by: Pietro Cerutti <gahr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libebur128
PORTVERSION=	1.0.2
DISTVERSIONPREFIX=	v
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Implementation of the EBU R128 loudness standard

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libspeexdsp.so:${PORTSDIR}/audio/speexdsp

USE_GITHUB=	yes
GH_ACCOUNT=	jiixyj

USES=		cmake:outsource pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
