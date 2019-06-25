# Created by: Vladimir Chukharev
# $FreeBSD$

PORTNAME=	robotframework-ride
PORTVERSION=	1.5.2.1
PORTREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	Vladimir.Chukharev@gmail.com
COMMENT=	Test data editor for Robot Framework

LICENSE=	APACHE20

BROKEN=		Not compatible with wxWidgets 3.0 or later

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}robotframework>=2.7.5:devel/py-robotframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}robotframework-seleniumlibrary>=1.1.0:devel/py-robotframework-seleniumlibrary@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pygments>0:textproc/py-pygments@${PY_FLAVOR}

NO_ARCH=	yes
USES=		python:-2.7
USE_PYTHON=	autoplist distutils
USE_WX=		3.0+
WX_COMPS=	python:run

.include <bsd.port.mk>
