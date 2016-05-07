# Created by: Wen Heping <wen@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zope.i18n
PORTVERSION=	3.8.0
PORTREVISION=	1
CATEGORIES=	devel www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope Internationalization Support

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.event>=0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.component>=0:devel/py-zope.component \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>=0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.3.0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz

USES=		gettext python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
