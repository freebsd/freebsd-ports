# $FreeBSD$

PORTNAME=	zope.app.file
PORTVERSION=	3.6.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	File and Image -- Zope 3 Content Components

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}transaction>0:devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zope.app.publication>0:devel/py-zope.app.publication \
		${PYTHON_PKGNAMEPREFIX}zope.contenttype>0:devel/py-zope.contenttype \
		${PYTHON_PKGNAMEPREFIX}zope.datetime>0:devel/py-zope.datetime \
		${PYTHON_PKGNAMEPREFIX}zope.dublincore>0:devel/py-zope.dublincore \
		${PYTHON_PKGNAMEPREFIX}zope.event>0:devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.exceptions>0:devel/py-zope.exceptions \
		${PYTHON_PKGNAMEPREFIX}zope.filerepresentation>0:devel/py-zope.filerepresentation \
		${PYTHON_PKGNAMEPREFIX}zope.i18nmessageid>0:textproc/py-zope.i18nmessageid \
		${PYTHON_PKGNAMEPREFIX}zope.interface>0:devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>0:devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.site>0:devel/py-zope.site \
		${PYTHON_PKGNAMEPREFIX}zope.size>0:devel/py-zope.size \
		zodb${PYTHON_PKGNAMESUFFIX}>0:databases/zodb3

NO_ARCH=	yes
USES=		python:2.7
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
