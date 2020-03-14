# $FreeBSD$

PORTNAME=	pynvim
DISTVERSION=	0.4.0
CATEGORIES=	editors python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

PATCH_SITES=	https://github.com/neovim/pynvim/commit/
PATCHFILES=	f04853121de564ac03b981a984595ea33331ad3e.patch:-p1

MAINTAINER=	tm@NetBSD.org
COMMENT=	Python client and plugin host for Neovim

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}msgpack>=0.5.0:devel/py-msgpack@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}greenlet>=0:devel/py-greenlet@${PY_FLAVOR}
py27_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}trollius>=0:devel/py-trollius@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=3.4.0:devel/py-pytest@${PY_FLAVOR}

USES=		python
USE_PYTHON=	concurrent distutils flavors autoplist
# XXX: Switch to CHEESESHOP once https://github.com/neovim/pynvim/issues/367
# is resolved.
USE_GITHUB=	yes
GH_ACCOUNT=	neovim

NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		SUFFIX_FOR_PYTHON_3=${PYTHON_MAJOR_VER:M3}

maintainer-test:
# Cannot depend on neovim as it could create a circular dependency
	@${ECHO_CMD} "===> Install neovim, then run:"
	@${ECHO_CMD} "cd ${WRKSRC} && ${PYTHON_CMD} -m pytest"

.include <bsd.port.mk>
