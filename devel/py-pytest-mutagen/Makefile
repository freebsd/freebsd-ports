PORTNAME=	pytest-mutagen
PORTVERSION=	1.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Add the mutation testing feature to pytest

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}

USE_GITHUB=	yes  # LICENSE and tests are missing from PyPI distribution
GH_ACCOUNT=	timpaquatte
GH_TAGNAME=	b4cc63c  # 1.3 tag is also missing

USES=		python:3.6+
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes
TEST_ENV=	PYTHONPATH="${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}"

do-test:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -v -rs

.include <bsd.port.mk>
