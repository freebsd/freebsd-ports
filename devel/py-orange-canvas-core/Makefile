PORTNAME=	orange-canvas-core
DISTVERSION=	0.1.20
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Core component of Orange Canvas

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}AnyQt>=0.0.11:x11-toolkits/py-AnyQt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}CommonMark>=0.8.1:textproc/py-CommonMark@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachecontrol>0:devel/py-cachecontrol@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dictdiffer>0:misc/py-dictdiffer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pip>=18.0:devel/py-pip@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qasync>0:devel/py-qasync@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
