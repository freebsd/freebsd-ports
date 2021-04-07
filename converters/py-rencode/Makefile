PORTNAME=	rencode
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	converters devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web safe object pickling/unpickling

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

# Make setup.py test target work with setup.py:test_suite
# See: files/patch-setup.py
post-patch:
	${TOUCH} ${WRKSRC}/tests/__init__.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rencode/_rencode*.so

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
