# Created by: Johannes Meixner <johannes@perceivon.net>

PORTNAME=	memory-profiler
PORTVERSION=	0.58.0
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	memory_profiler-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for monitoring memory usage of a python program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psutil>=0:sysutils/py-psutil@${PY_FLAVOR}

USES=		python:3.7+
USE_PYTHON=	autoplist concurrent distutils

NO_ARCH=	yes

OPTIONS_DEFINE=	MATPLOTLIB
MATPLOTLIB_DESC=Plot support via matplotlib

MATPLOTLIB_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR}

.include <bsd.port.mk>
