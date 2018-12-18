# $FreeBSD$

PORTNAME=	rtichoke
DISTVERSION=	0.2.14
CATEGORIES=	devel math python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	21st century R console

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lineedit>=0.1.1:devel/py-lineedit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rapi>=0.1.2:math/py-rapi@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
