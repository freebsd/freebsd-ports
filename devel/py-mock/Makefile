# Created by: jessekempf@gmail.com
# $FreeBSD$

PORTNAME=	mock
PORTVERSION=	3.0.5
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Rolling backport of unittest.mock for all Pythons

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes # tests not packages in PyPI sdist
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

GH_ACCOUNT=	testing-cabal

.include <bsd.port.pre.mk>

.if ${PYTHON_VER} < 3.3
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}funcsigs>=1:devel/py-funcsigs@${PY_FLAVOR}
.endif

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} -m pytest -v -rs -o addopts=

.include <bsd.port.post.mk>
