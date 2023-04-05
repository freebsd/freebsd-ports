PORTNAME=	s2
PORTVERSION=	0.10.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of S2 Geometry Library
WWW=		https://s2geometry.io/ \
		https://github.com/google/s2geometry

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	s2>=${PORTVERSION}<${PORTVERSION}_99:graphics/s2 \
		swig>=4:devel/swig
LIB_DEPENDS=	libs2.so:graphics/s2

USES=		cmake compiler:c++17-lang localbase:ldflags python

CMAKE_ON=	WITH_PYTHON
USE_CXXSTD=	c++17

WRKSRC_SUBDIR=	src/python

GH_ACCOUNT=	google
GH_PROJECT=	s2geometry
USE_GITHUB=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64 && !defined(CPUTYPE)
CXXFLAGS+=	-mcpu=power7
.endif

.include <bsd.port.mk>
