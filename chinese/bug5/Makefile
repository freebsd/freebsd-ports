# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	bug5
PORTVERSION=	1.17
CATEGORIES=	chinese converters
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	Big5/GBK <-> UTF-8 translating layer in terminal

LICENSE=	BSD

LIB_DEPENDS=	libbsdconv.so:${PORTSDIR}/converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	992e2d3

MAKE_ARGS=	PREFIX=${PREFIX}

PLIST_FILES=	bin/bug5

.include <bsd.port.mk>
