# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	opencc
PORTVERSION=	1.0
CATEGORIES=	chinese converters
PKGNAMEPREFIX=	bsdconv-
DISTNAME=	${GH_ACCOUNT}-${GH_PROJECT}-${PORTVERSION}-0-g${GH_COMMIT}

MAINTAINER=	buganini@gmail.com
COMMENT=	OpenCC conversion module for bsdconv

LICENSE=	BSD

BUILD_DEPENDS=	bsdconv_mktable:${PORTSDIR}/converters/bsdconv
LIB_DEPENDS=	bsdconv:${PORTSDIR}/converters/bsdconv \
		opencc:${PORTSDIR}/chinese/opencc

USE_GITHUB=	yes
GH_ACCOUNT=	buganini
GH_PROJECT=	bsdconv-${PORTNAME}
GH_COMMIT=	be3e559

MAKE_ARGS=	PREFIX=${PREFIX}

.include <bsd.port.mk>
