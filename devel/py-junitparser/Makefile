PORTNAME=	junitparser
DISTVERSION=	5.0.1
CATEGORIES=	devel net
#MASTER_SITES=	PYPI # some test files are missing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Manipulating JUnit/xUnit Result XML files
WWW=		https://junitparser.readthedocs.io/en/latest/ \
		https://github.com/weiwei/junitparser

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}uv-build>0:devel/py-uv-build@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 concurrent autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	weiwei

NO_ARCH=	yes
TEST_ARGS=	tests

post-patch:
	@${REINPLACE_CMD} -e 's|version = _dist_version("junitparser")|version = "${DISTVERSION}"|' \
		${WRKSRC}/src/junitparser/__init__.py

# tests as of 5.0.1: 127 passed, 2 skipped in 0.51s

.include <bsd.port.mk>
