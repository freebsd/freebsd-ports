PORTNAME=	srsly
PORTVERSION=	2.4.1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Modern high-performance serialization utilities for Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}catalogue>=2.0.1<2.1.0:devel/py-catalogue@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist concurrent cython distutils

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/srsly/*/*.so

.include <bsd.port.mk>
