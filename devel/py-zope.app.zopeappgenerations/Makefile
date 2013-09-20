# $FreeBSD$

PORTNAME=	zope.app.zopeappgenerations
PORTVERSION=	3.6.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Application ZODB Update Generations

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.annotation>=0:${PORTSDIR}/devel/py-zope.annotation \
		${PYTHON_PKGNAMEPREFIX}zope.app.authentication>=0:${PORTSDIR}/security/py-zope.app.authentication \
		${PYTHON_PKGNAMEPREFIX}zope.app.component>=0:${PORTSDIR}/devel/py-zope.app.component \
		${PYTHON_PKGNAMEPREFIX}zope.copypastemove>=0:${PORTSDIR}/devel/py-zope.copypastemove \
		${PYTHON_PKGNAMEPREFIX}zope.dublincore>=0:${PORTSDIR}/devel/py-zope.dublincore \
		${PYTHON_PKGNAMEPREFIX}zope.generations>=0:${PORTSDIR}/devel/py-zope.generations

DIST_SUBDIR=	zope
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
