PORTNAME=	rencode
PORTVERSION=	1.0.6
PORTREVISION=	2
CATEGORIES=	converters devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Web safe object pickling/unpickling
WWW=		https://github.com/aresch/rencode

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cython3>0:lang/cython3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0:devel/py-wheel@${PY_FLAVOR}

USES=		cpe python
CPE_VENDOR=	${PORTNAME}_project
USE_PYTHON=	autoplist pep517

USE_GITHUB=	yes
GH_ACCOUNT=	aresch
GH_TAGNAME=	572ff74586d9b1daab904c6f7f7009ce0143bb75

# Make setup.py test target work with setup.py:test_suite
# See: files/patch-setup.py
post-patch:
	${TOUCH} ${WRKSRC}/tests/__init__.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/rencode/_rencode*.so

do-test:
	cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
