# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	s2
PORTVERSION=	0.9.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of S2 Geometry Library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../../LICENSE

BUILD_DEPENDS=	s2>=${PORTVERSION}:graphics/s2 \
		swig:devel/swig
LIB_DEPENDS=	libs2.so:graphics/s2

USES=		cmake localbase:ldflags python

WRKSRC_SUBDIR=	src/python

GH_ACCOUNT=	google
GH_PROJECT=	s2geometry
USE_GITHUB=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc64
USES+=		compiler:gcc-c++11-lib
.else
USES+=		compiler:c++11-lang
.endif

.include <bsd.port.mk>
