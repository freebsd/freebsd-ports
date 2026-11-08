PORTNAME=	mktestdocs
DISTVERSION=	0.2.5
CATEGORIES=	devel python
#MASTER_SITES=	PYPI # incomplete test data
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Run pytest against markdown files and docstrings
WWW=		https://github.com/koaning/mktestdocs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

USE_GITHUB=	yes
GH_ACCOUNT=	koaning

TEST_ENV=	${MAKE_ENV} PYTHONPATH=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 0.2.5: 39 passed, 2 warnings

.include <bsd.port.mk>
