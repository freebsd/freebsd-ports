# $FreeBSD$

PORTNAME=	zope.filerepresentation
PORTVERSION=	3.6.1
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	File-system Representation Interfaces

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/%%PYEASYINSTALL_EGG%%
USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install

NO_STAGE=	yes
.include <bsd.port.mk>
