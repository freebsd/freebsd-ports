# $FreeBSD$

PORTNAME=	zope.container
PORTVERSION=	3.12.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Container

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.location>=3.5.4:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=3.5.2:devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>=0:devel/py-zope.filerepresentation \
		${PYTHON_PKGNAMEPREFIX}zope.size>=0:devel/py-zope.size \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.broken>=0:devel/py-zope.broken \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:devel/py-zope.configuration

USES=		python zip
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
