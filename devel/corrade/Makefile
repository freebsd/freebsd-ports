# $FreeBSD$

PORTNAME=	corrade
DISTVERSIONPREFIX=	v
DISTVERSION=	2019.01
CATEGORIES=	devel

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	7a84146a077551f6c1e985a153642fb50d3e72ef.patch:-p1

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++11/C++14 multiplatform utility library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang
USE_GITHUB=	yes
GH_ACCOUNT=	mosra
GH_TUPLE=	mosra:toolchains:a3e0aff:t/toolchains
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DLIB_SUFFIX:STRING=""

.include <bsd.port.mk>
