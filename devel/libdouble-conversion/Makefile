# Created by: Waitman Gobble <waitman@waitman.net>
# $FreeBSD$

PORTNAME=	libdouble-conversion
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	waitman@waitman.net
COMMENT=	Binary-decimal and decimal-binary routines for IEEE doubles

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	Fails to build: Target architecture was not detected as supported by Double-Conversion

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	waitman
GH_TAGNAME=	e9b9e5a

.include <bsd.port.mk>
