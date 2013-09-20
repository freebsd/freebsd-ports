# $FreeBSD$

PORTNAME=	zope.app.testing
PORTVERSION=	3.10.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Application Testing Support

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:${PORTSDIR}/devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.app.appsetup>=3.11.0:${PORTSDIR}/devel/py-zope.app.appsetup \
		${PYTHON_PKGNAMEPREFIX}zope.processlifetime>=0:${PORTSDIR}/devel/py-zope.processlifetime \
		${PYTHON_PKGNAMEPREFIX}zope.app.debug>=0:${PORTSDIR}/devel/py-zope.app.debug \
		${PYTHON_PKGNAMEPREFIX}zope.app.dependable>=0:${PORTSDIR}/devel/py-zope.app.dependable \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>=0:${PORTSDIR}/devel/py-zope.app.publication \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.container>=0:${PORTSDIR}/devel/py-zope.container \
		${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.password>=0:${PORTSDIR}/security/py-zope.password \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.site>=0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.testbrowser>=4.0.0:${PORTSDIR}/devel/py-zope.testbrowser \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:${PORTSDIR}/devel/py-zope.traversing

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
