# $FreeBSD$

PORTNAME=	zope.app.publisher
PORTVERSION=	3.10.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Means for configuration of Zope 3 style views and resources

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.browsermenu>=0:${PORTSDIR}/devel/py-zope.browsermenu \
		${PYTHON_PKGNAMEPREFIX}zope.browserpage>=0:${PORTSDIR}/devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>=0:${PORTSDIR}/devel/py-zope.browserresource \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.datetime>=0:${PORTSDIR}/devel/py-zope.datetime \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.ptresource>=0:${PORTSDIR}/devel/py-zope.ptresource \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=3.12:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.componentvocabulary>=0:${PORTSDIR}/devel/py-zope.componentvocabulary

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
