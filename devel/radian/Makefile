# $FreeBSD$

PORTNAME=	radian
DISTVERSION=	0.3.4
PORTREVISION=	1
CATEGORIES=	devel math python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	21st century R console

LICENSE=	MIT

BROKEN=		depends on package: pyXX-rchitect>=0.2.3,<0.3.0

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest-runner>=0:devel/py-pytest-runner@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}lineedit>=0.1.1:devel/py-lineedit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rchitect>=0.2.3,<0.3.0:devel/py-rchitect@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>=1.9.0:devel/py-six@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
