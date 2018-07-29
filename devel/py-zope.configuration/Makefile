# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zope.configuration
PORTVERSION=	4.1.0
PORTREVISION=	0
CATEGORIES=	devel textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Configuration Markup Language (ZCML)

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema@${PY_FLAVOR}

USES=		python
USE_PYTHON=	distutils autoplist

NO_ARCH=	yes

.include <bsd.port.mk>
