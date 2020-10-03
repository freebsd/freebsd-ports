# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	h3
PORTVERSION=	3.7.0
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python binding of H3 library

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	cmake:devel/cmake \
		h3>=${PORTVERSION}:graphics/h3 \
		${PYTHON_PKGNAMEPREFIX}scikit-build>=0:devel/py-scikit-build@${PY_FLAVOR}
LIB_DEPENDS=	libh3.so:graphics/h3

USES=		localbase:ldflags python
USE_PYTHON=	autoplist concurrent cython distutils

CFLAGS+=	-I${LOCALBASE}/include/h3

OPTIONS_DEFINE=	NUMPY
OPTIONS_DEFAULT=NUMPY
NUMPY_DESC=	NumPy support

NUMPY_RUN_DEPENDS=	${PYNUMPY}

.include <bsd.port.mk>
