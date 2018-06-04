# Created by: Waitman Gobble <waitman@waitman.net>
# $FreeBSD$

PORTNAME=	libdouble-conversion
PORTVERSION=	3.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	waitman@waitman.net
COMMENT=	Binary-decimal and decimal-binary routines for IEEE doubles

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

#BROKEN_aarch64=	Fails to build: Target architecture was not detected as supported by Double-Conversion

USES=		cmake
USE_LDCONFIG=	yes
CMAKE_ARGS=	-DCMAKE_POSITION_INDEPENDENT_CODE=1

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	double-conversion

.include <bsd.port.mk>
