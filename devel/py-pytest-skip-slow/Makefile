PORTNAME=	pytest-skip-slow
DISTVERSION=	1.1.0
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_skip_slow-${DISTVERSION}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Pytest plugin to skip @pytest.mark.slow tests by default
WWW=		https://github.com/okken/pytest-skip-slow

LICENSE=	MIT

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}flit-core>=3.11:devel/py-flit-core@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=6.2.0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	pep517 autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
