PORTNAME=	pillow-heif
PORTVERSION=	0.22.0
PORTREVISION=	1
CATEGORIES=	graphics python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pillow_heif-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python interface for libheif library
WWW=		https://github.com/bigcat88/pillow_heif

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}setuptools>=61:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}
LIB_DEPENDS=	libheif.so:graphics/libheif
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>=10.1.0:graphics/py-pillow@${PY_FLAVOR}

USES=		localbase python:3.9+
USE_PYTHON=	autoplist concurrent pep517

LDFLAGS+=	-lheif

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/libheif/

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
