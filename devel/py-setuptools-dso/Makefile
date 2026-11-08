PORTNAME=	setuptools-dso
DISTVERSION=	2.12.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/_/}-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Setuptools extension to build non-python shared libraries
WWW=		https://github.com/mdavidsaver/setuptools_dso

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PY_SETUPTOOLS} \
		${PYTHON_PKGNAMEPREFIX}wheel>0:devel/py-wheel@${PY_FLAVOR}
RUN_DEPENDS=	${PY_SETUPTOOLS}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	--disable-plugin-autoload

NO_ARCH=	yes

# tests as of 2.12.4: 7 passed, 1 warning in 0.81s

.include <bsd.port.mk>
