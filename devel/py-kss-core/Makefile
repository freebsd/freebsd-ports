# $FreeBSD$

PORTNAME=	kss-core
PORTVERSION=	1.6.5
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:S/-/./}-${PORTVERSION}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	KSS (Kinetic Style Sheets) core framework

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.browserpage>0:${PORTSDIR}/devel/py-zope.browserpage \
		${PYTHON_PKGNAMEPREFIX}zope.browserresource>0:${PORTSDIR}/devel/py-zope.browserresource \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:${PORTSDIR}/devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.configuration>=0:${PORTSDIR}/devel/py-zope.configuration \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>=0:${PORTSDIR}/devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.datetime>=0:${PORTSDIR}/devel/py-zope.datetime \
		${PYTHON_PKGNAMEPREFIX}zope.event>=0:${PORTSDIR}/devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.lifecycleevent>=0:${PORTSDIR}/devel/py-zope.lifecycleevent \
		${PYTHON_PKGNAMEPREFIX}zope.location>=0:${PORTSDIR}/devel/py-zope.location \
		${PYTHON_PKGNAMEPREFIX}zope.pagetemplate>=0:${PORTSDIR}/devel/py-zope.pagetemplate \
		${PYTHON_PKGNAMEPREFIX}zope.publisher>=0:${PORTSDIR}/devel/py-zope.publisher \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.security>=0:${PORTSDIR}/security/py-zope.security \
		${PYTHON_PKGNAMEPREFIX}zope.site>0:${PORTSDIR}/devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}zope.traversing>=0:${PORTSDIR}/devel/py-zope.traversing

DIST_SUBDIR=	zope
USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	${PORTNAME:S/-/./}
USE_ZIP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
