PORTNAME=	libsedml
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.27
CATEGORIES=	biology devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	SED-ML library for Python

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/../../../LICENSE.txt

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libsedml.so:biology/libsedml \
		libsbml.so:biology/libsbml \
		libnuml.so:biology/libnuml

USES=		cmake localbase:ldflags python
USE_PYTHON=	flavors

USE_GITHUB=	yes
GH_ACCOUNT=	fbergmann
GH_PROJECT=	libSEDML

CMAKE_ARGS=	-DCMAKE_INSTALL_LIBDIR=lib

LDFLAGS+=	-lsedml -lsbml -lnuml # otherwise it builds a broken shared object, see https://github.com/NuML/NuML/issues/21

WRKSRC_SUBDIR=	src/bindings/python

do-test: install
	@${PYTHON_CMD} ${FILESDIR}/quick-test.py

.include <bsd.port.mk>
