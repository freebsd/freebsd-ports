# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	chiconv
PORTVERSION=	10.0
CATEGORIES=	chinese converters
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	Auto chinese encoding converter

LICENSE=	BSD

LIB_DEPENDS=	bsdconv:${PORTSDIR}/converters/bsdconv

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_COMMIT=	6f4a7bf

MAKE_ARGS=	PREFIX=${PREFIX}

PLIST_FILES=	bin/chiconv

NO_STAGE=	yes
.include <bsd.port.mk>
