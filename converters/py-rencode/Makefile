PORTNAME=	rencode
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	converters devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web safe object pickling/unpickling
WWW=		https://github.com/aresch/rencode

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
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
