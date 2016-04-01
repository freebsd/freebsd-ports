# $FreeBSD$

PORTNAME=	zope.app.publication
PORTVERSION=	3.14.0
PORTREVISION=	1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope publication

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.authentication>=0:security/py-zope.authentication \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.error>=0:devel/py-zope.error \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=1.2:devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.12.4:devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=3.9.0:devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}transaction>=1.1.0:devel/py-transaction

USES=		python
USE_PYTHON=	distutils autoplist

.include <bsd.port.mk>
