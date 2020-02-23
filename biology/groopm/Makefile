# $FreeBSD$

PORTNAME=	GroopM
DISTVERSION=	0.3.4
PORTREVISION=	2
CATEGORIES=	biology python
MASTER_SITES=	CHEESESHOP

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Metagenomic binning suite

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1.0:math/py-matplotlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scipy>=0.10.1:science/py-scipy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tables>=2.3:devel/py-tables@${PY_FLAVOR}

USES=		python:2.7
USE_PYTHON=	distutils noflavors autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
