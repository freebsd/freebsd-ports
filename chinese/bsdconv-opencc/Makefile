# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	opencc
PORTVERSION=	11.1
CATEGORIES=	chinese converters
PKGNAMEPREFIX=	bsdconv-

MAINTAINER=	buganini@gmail.com
COMMENT=	OpenCC conversion module for bsdconv

LICENSE=	ISCL

BUILD_DEPENDS=	${LOCALBASE}/bin/bsdconv-mktable:${PORTSDIR}/converters/bsdconv
LIB_DEPENDS=	libbsdconv.so:${PORTSDIR}/converters/bsdconv \
		libopencc.so:${PORTSDIR}/chinese/opencc

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	${PKGNAMEPREFIX}${PORTNAME}

.include <bsd.port.mk>
