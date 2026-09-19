PORTNAME=	pyTooling
DISTVERSIONPREFIX=	v
DISTVERSION=	9.0.0
CATEGORIES=	devel
#MASTER_SITES=	PYPI # requirements.txt is missing
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of arbitrary classes, decorators, meta-classes, exceptions
WWW=		https://pytooling.github.io/pyTooling/ \
		https://github.com/pyTooling/pyTooling

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>=0.40.0:devel/py-wheel@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}aiohttp>=3.12:www/py-aiohttp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>=9.1:devel/py-pytest@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ruamel.yaml>=0.19.1:devel/py-ruamel.yaml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist
USE_GITHUB=	yes

NO_ARCH=	yes

TEST_ARGS=	--disable-plugin-autoload
TEST_WRKSRC=	${WRKSRC}

do-test:
	cd ${TEST_WRKSRC} && ${PYTHON_CMD} -m pytest ${TEST_ARGS} tests/unit -k 'not ExplicitPathsOnWindows and not ExplicitPathsOnLinux and not ExplicitBinaryDirectoryOnWindows and not ExplicitBinaryDirectoryOnLinux and not Packaging and not test_TypeConvertToInt and not test_LineTerminal' -v

# tests as of 9.0.0: 1311 passed, 16 skipped, 29 deselected, 3 xfailed, 93 subtests passed in 35.40s

.include <bsd.port.mk>
