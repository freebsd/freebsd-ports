# $FreeBSD$

PORTNAME=	zope.app.appsetup
PORTVERSION=	3.16.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope app setup helper

LICENSE=	ZPL21

RUN_DEPENDS=	zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:${PORTSDIR}/devel/py-zope.app.publication \
		${PYTHON_PKGNAMEPREFIX}zope.component>=3.8.0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:${PORTSDIR}/devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.error>=0:${PORTSDIR}/devel/py-zope.error \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:${PORTSDIR}/devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:${PORTSDIR}/devel/py-zope.processlifetime \
		${PYTHON_PKGNAMEPREFIX}zope.security>=3.6.0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.session>=0:${PORTSDIR}/security/py-zope.session \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:${PORTSDIR}/devel/py-zope.traversing

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
