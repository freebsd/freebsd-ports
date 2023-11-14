PORTNAME=	lief
DISTVERSION=	0.11.5
CATEGORIES=	devel python
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@nicandneal.net
COMMENT=	Library to instrument executable formats
WWW=		https://github.com/lief-project/lief

LICENSE=	APACHE20

# Note: cmake is needed to build, but distutils is used directly.
# If USES= cmake is set, the build will not work.
BUILD_DEPENDS=	cmake:devel/cmake-core

USES=		python zip
USE_PYTHON=	concurrent distutils

PY_VER=		${PYTHON_VER:S/.//}
PLIST_SUB=	PY_VER=${PY_VER}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PYTHON_SITELIBDIR}/lief.cpython-${PY_VER}.so

.include <bsd.port.mk>
