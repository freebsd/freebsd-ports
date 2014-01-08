# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	opencc
PORTVERSION=	11.1
CATEGORIES=	chinese converters
PKGNAMEPREFIX=	bsdconv-
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	OpenCC conversion module for bsdconv

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/bin/bsdconv-mktable:${PORTSDIR}/converters/bsdconv
LIB_DEPENDS=	libbsdconv.so:${PORTSDIR}/converters/bsdconv \
		libopencc.so:${PORTSDIR}/chinese/opencc

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}
GH_COMMIT=	c48c74c

NO_STAGE=	yes

.include <bsd.port.mk>
