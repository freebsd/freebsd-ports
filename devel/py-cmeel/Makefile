PORTNAME=	cmeel
DISTVERSION=	0.60.1
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Python build backend for CMake projects (cmeel)
WWW=		https://github.com/cmake-wheel/cmeel

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hatchling>0:devel/py-hatchling@${PY_FLAVOR}
RUN_DEPENDS=	cmake:devel/cmake \
		${PYTHON_PKGNAMEPREFIX}packaging>0:devel/py-packaging@${PY_FLAVOR}

USES=		python shebangfix
USE_PYTHON=	pep517 autoplist

SHEBANG_FILES=	cmeel/release.py

NO_ARCH=	yes

.include <bsd.port.mk>
