PORTNAME=	setuptools-dso
DISTVERSION=	2.12.3
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

TEST_ARGS=	-p no:relaxed

NO_ARCH=	yes

# tests as of 2.12.3: 7 passed, 1 warning in 1.11s

.include <bsd.port.mk>
