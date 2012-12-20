# $FreeBSD$

PORTNAME=	Products.PythonScripts
PORTVERSION=	2.13.2
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Support for restricted execution of Python scripts in Zope 2

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}AccessControl>=0:${PORTSDIR}/security/py-AccessControl \
		${PYTHON_PKGNAMEPREFIX}Acquisition>=0:${PORTSDIR}/devel/py-Acquisition \
		${PYTHON_PKGNAMEPREFIX}DateTime>=0:${PORTSDIR}/devel/py-DateTime \
		${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:${PORTSDIR}/devel/py-DocumentTemplate \
		${PYTHON_PKGNAMEPREFIX}RestrictedPython>=0:${PORTSDIR}/security/py-RestrictedPython \
		${PYTHON_PKGNAMEPREFIX}zExceptions>=0:${PORTSDIR}/devel/py-zExceptions

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
