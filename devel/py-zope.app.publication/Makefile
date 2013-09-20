# $FreeBSD$

PORTNAME=	zope.app.publication
PORTVERSION=	3.14.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope publication

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.authentication>=0:${PORTSDIR}/security/py-zope.authentication \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.error>=0:${PORTSDIR}/devel/py-zope.error \
		${PYTHON_PKGNAMEPREFIX}zope.browser>=1.2:${PORTSDIR}/devel/py-zope.browser \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.12.4:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=3.9.0:${PORTSDIR}/devel/py-zope.traversing \
		${PYTHON_PKGNAMEPREFIX}transaction>=1.1.0:${PORTSDIR}/devel/py-transaction

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
