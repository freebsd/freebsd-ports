PORTNAME=	pyplusplus
DISTVERSION=	1.8.5
CATEGORIES=	devel
MASTER_SITES=	PYPI
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework of components for creating a C++ code generator
WWW=		https://github.com/ompl/pyplusplus

LICENSE=	BSL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygccxml>0:textproc/py-pygccxml@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygccxml>0:textproc/py-pygccxml@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
