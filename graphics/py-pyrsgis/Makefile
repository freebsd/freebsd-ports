# Created by: Rainer Hurling <rhurlin@gwdg.de>

PORTNAME=	pyrsgis
PORTVERSION=	0.3.5
CATEGORIES=	graphics python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rhurlin@FreeBSD.org
COMMENT=	Processing satellite data directly from TAR files

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gdal>=0:graphics/py-gdal@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}matplotlib-scalebar>=0:math/py-matplotlib-scalebar@${PY_FLAVOR} \
		${PYNUMPY}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils

NO_ARCH=	yes

.include <bsd.port.mk>
