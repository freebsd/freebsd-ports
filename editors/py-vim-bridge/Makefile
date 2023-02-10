PORTNAME=	vim-bridge
DISTVERSION=	0.6
CATEGORIES=	editors python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Decorator enabing transparent calls to Python functions in Vim scripts
WWW=		https://github.com/nvie/vim_bridge

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/setup.py

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>=0:devel/py-mock@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
GH_ACCOUNT=	nvie
GH_PROJECT=	vim_bridge
USE_PYTHON=	autoplist concurrent distutils flavors

NO_ARCH=	yes

do-test:
	@(cd ${TEST_WRKSRC} && \
		${SETENV} ${TEST_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test)

.include <bsd.port.mk>
