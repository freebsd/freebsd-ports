# $FreeBSD$

PORTNAME=	collective.z3cform.datetimewidget
PORTVERSION=	1.2.5
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	zope@FreeBSD.org
COMMENT=	z3c.form date and datetime widgets

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.i18n>=0:${PORTSDIR}/devel/py-zope.i18n \
		${PYTHON_PKGNAMEPREFIX}z3c.form>=0:${PORTSDIR}/devel/py-z3c.form \
		${PYTHON_PKGNAMEPREFIX}zope.deprecation>=0:${PORTSDIR}/devel/py-zope.deprecation

DIST_SUBDIR=	zope
USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes

.include <bsd.port.mk>
