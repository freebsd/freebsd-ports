PORTNAME=	pytest-mutagen
PORTVERSION=	1.3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Add the mutation testing feature to pytest
WWW=		https://pypi.org/project/pytest-mutagen/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hypothesis>=0:devel/py-hypothesis@${PY_FLAVOR}

USE_GITHUB=	yes  # LICENSE and tests are missing from PyPI distribution
GH_ACCOUNT=	timpaquatte
GH_TAGNAME=	b4cc63c  # 1.3 tag is also missing

USES=		python
USE_PYTHON=	autoplist distutils pytest
NO_ARCH=	yes
PYTEST_BROKEN_TESTS=	test_BST_mutations test_short_example test_separate_files

.include <bsd.port.mk>
