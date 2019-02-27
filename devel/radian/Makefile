# $FreeBSD$

PORTNAME=	radian
DISTVERSION=	0.3.2
CATEGORIES=	devel math python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	21st century R console

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lineedit>=0.1.1:devel/py-lineedit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapi>=0.1.2:math/py-rapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rchitect>=0.2.3,<0.3.0:devel/py-rchitect@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
