PORTNAME=	pyplusplus
DISTVERSION=	1.8.4
CATEGORIES=	devel
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Framework of components for creating a C++ code generator

LICENSE=	BSL

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygccxml>0:textproc/py-pygccxml@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pygccxml>0:textproc/py-pygccxml@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist
NO_ARCH=	yes

.include <bsd.port.mk>
