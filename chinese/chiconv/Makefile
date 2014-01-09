# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	chiconv
PORTVERSION=	11.1
CATEGORIES=	chinese converters
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	Auto chinese encoding converter

LICENSE=	BSD

LIB_DEPENDS=	libbsdconv.so:${PORTSDIR}/converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	9501c80

MAKE_ARGS=	PREFIX=${PREFIX}

PLIST_FILES=	bin/chiconv

.include <bsd.port.mk>
