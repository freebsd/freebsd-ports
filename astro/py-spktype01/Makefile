# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	spktype01
PORTVERSION=	1.0.0
CATEGORIES=	astro python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Supporting module for jplephem to handle data type 1

LICENSE=	MIT

BUILD_DEPENDS=	${NUMPY}
RUN_DEPENDS=	${NUMPY}	\
		${PYTHON_PKGNAMEPREFIX}jplephem>0:astro/py-jplephem@${PY_FLAVOR}

USE_GITHUB=	yes
GH_ACCOUNT=	whiskie14142
GH_TAGNAME=	964cc70

USES=		python:3.7+
USE_PYTHON=	distutils

WRKSRC_SUBDIR=	package/${PORTNAME}
TEST_WRKSRC=	${WRKSRC}/../../test
NO_ARCH=	yes

PLIST_FILES=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/__pycache__/spktype01.cpython-${PYTHON_SUFFIX}.opt-1.pyc \
		${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/__pycache__/spktype01.cpython-${PYTHON_SUFFIX}.pyc \
		${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}/spktype01.py

.include <bsd.port.mk>
