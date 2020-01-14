# $FreeBSD$

PORTNAME=	tempstorage
PORTVERSION=	2.12.2
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	RAM-based storage for ZODB

LICENSE=	ZPL21

DEPRECATED=	Old, uses EOLed python27
EXPIRATION_DATE=	2020-02-18

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=3.9.0:databases/zodb3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.testing>0:devel/py-zope.testing@${PY_FLAVOR}

USES=		python:2.7 zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
