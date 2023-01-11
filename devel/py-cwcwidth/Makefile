PORTNAME=	cwcwidth
PORTVERSION=	0.1.8
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python bindings for wc(s)width
WWW=		https://github.com/sebastinas/cwcwidth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython>=0.28:lang/cython@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${FIND} ${STAGEDIR}${PYTHON_SITELIBDIR} -name '*.so' -exec ${STRIP_CMD} {} +

.include <bsd.port.mk>
