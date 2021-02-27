# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	spktype21
PORTVERSION=	0.1.0
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Supporting module for jplephem to handle data type 21

LICENSE=	MIT

BUILD_DEPENDS=	${NUMPY}
RUN_DEPENDS=	${NUMPY}	\
		${PYTHON_PKGNAMEPREFIX}jplephem>0:astro/py-jplephem@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}spktype01>0:astro/py-spktype01@${PY_FLAVOR} \
		py.test:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	whiskie14142
GH_TAGNAME=	7ed2236

USES=		python:3.7+
USE_PYTHON=	distutils

WRKSRC_SUBDIR=	package/${PORTNAME}
TEST_WRKSRC=	${WRKSRC}/../../test
NO_ARCH=	yes

PLIST_FILES=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/__pycache__/spktype21.cpython-${PYTHON_SUFFIX}.opt-1.pyc \
		${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/__pycache__/spktype21.cpython-${PYTHON_SUFFIX}.pyc \
		${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/spktype21.py

.include <bsd.port.mk>
