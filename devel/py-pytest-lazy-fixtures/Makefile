PORTNAME=	pytest-lazy-fixtures
PORTVERSION=	1.3.4
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytest_lazy_fixtures-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Allow you to use fixtures in @pytest.mark.parametrize
WWW=		https://github.com/dev-petrov/pytest-lazy-fixtures

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>=0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=7,1:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	autoplist concurrent pep517

NO_ARCH=	yes

.include <bsd.port.mk>
