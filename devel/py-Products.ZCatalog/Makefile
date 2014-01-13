# $FreeBSD$

PORTNAME=	Products.ZCatalog
PORTVERSION=	2.13.23
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Zope2's indexing and search solution

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:${PORTSDIR}/security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:${PORTSDIR}/devel/py-DocumentTemplate \
		${PYTHON_PKGNAMEPREFIX}ExtensionClass>=0:${PORTSDIR}/devel/py-ExtensionClass \
		${PYTHON_PKGNAMEPREFIX}Missing>=0:${PORTSDIR}/devel/py-Missing \
		${PYTHON_PKGNAMEPREFIX}Persistence>=0:${PORTSDIR}/devel/py-Persistence \
		${PYTHON_PKGNAMEPREFIX}Products.ZCTextIndex>=0:${PORTSDIR}/devel/py-Products.ZCTextIndex \
		${PYTHON_PKGNAMEPREFIX}Record>=0:${PORTSDIR}/devel/py-Record \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:${PORTSDIR}/security/py-RestrictedPython \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:${PORTSDIR}/devel/py-zExceptions \
		zodb${PYTHON_PKGNAMESUFFIX}>=0:${PORTSDIR}/databases/zodb3 \
		${PYTHON_PKGNAMEPREFIX}zope.dottedname>=0:${PORTSDIR}/devel/py-zope.dottedname \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.schema>=0:${PORTSDIR}/devel/py-zope.schema \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=0:${PORTSDIR}/devel/py-zope.testing

USE_PYTHON=	2
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

NO_STAGE=	yes

.include <bsd.port.mk>
