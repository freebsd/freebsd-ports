PORTNAME=	libnuml
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.4
CATEGORIES=	biology devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Numerical Markup Language for Python

LICENSE=	LGPL21

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libnuml.so:biology/libnuml

USES=		cmake localbase:ldflags python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	NuML
GH_PROJECT=	NuML

WKSRC_SUBDIR=	${PORTNAME}/src/bindings/python

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR=lib

LDFLAGS+=	-lnuml # otherwise it builds a broken shared object, see https://github.com/NuML/NuML/issues/21

post-extract:
	@${RLN} ${WRKSRC}/../../../VERSION.txt ${WRKSRC}/VERSION.txt

.include <bsd.port.mk>
