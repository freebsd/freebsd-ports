PORTNAME=	rttr
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.6-16
PORTREVISION=	1
DISTVERSIONSUFFIX=	-gb3a131c
CATEGORIES=	devel

PATCH_SITES=	https://github.com/rttrorg/rttr/commit/
PATCHFILES=	992df30caa14fe6bfcd2c38213314622e1e02aae.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Run Time Type Reflection

LICENSE=	MIT

USES=		cmake compiler:c++11-lang
USE_GITHUB=	yes
GH_ACCOUNT=	rttrorg

CMAKE_OFF=	BUILD_DOCUMENTATION \
		BUILD_UNIT_TESTS

.include <bsd.port.mk>
