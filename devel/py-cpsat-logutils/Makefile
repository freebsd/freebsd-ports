PORTNAME=	cpsat-logutils
DISTVERSION=	1.0.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	cpsat_logutils-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Parse CP-SAT (OR-Tools) solver logs into pydantic models
WWW=		https://github.com/d-krupke/cpsat-logutils

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pydantic2>=2.10:devel/py-pydantic2@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist pytest

TEST_ARGS=	--disable-plugin-autoload -k 'not test_installed_ortools_log_parses'

NO_ARCH=	yes

# tests as of 1.0.0: 300 passed, 5 skipped

.include <bsd.port.mk>
