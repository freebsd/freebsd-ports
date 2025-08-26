PORTNAME=	stevedore
PORTVERSION=	5.5.0
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Manage dynamic plugins for Python applications
WWW=		https://docs.openstack.org/stevedore/latest/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

# pbr is a RUN_DEPENDS too, just declared elsewhere (requirements.txt)
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=234529
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=197373
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=6.1.1:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>=6.1.1:devel/py-pbr@${PY_FLAVOR}
USES=		python
USE_PYTHON=	autoplist distutils pytest

.if make(test)
# tests: 91 passed, 1 skipped
TEST_ENV=	PYTEST_DISABLE_PLUGIN_AUTOLOAD=1 \
		PYTHONPATH="${STAGEDIR}${PYTHON_SITELIBDIR}"
.endif

NO_ARCH=	yes

.include <bsd.port.mk>
