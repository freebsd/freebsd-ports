# New ports collection makefile for:	zodb3
# Date created:		8 Dezember 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	zodb
PORTVERSION=	3.10.3
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	-py${PYTHON_SUFFIX}
DISTNAME=	ZODB3-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	The Z - Object Database for python

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig \
		${LOCALBASE}/bin/zdaemon:${PORTSDIR}/sysutils/py-zdaemon \
		${PYTHON_PKGNAMEPREFIX}zope.interface>=3.3.0:${PORTSDIR}/devel/py-zope.interface \
		${PYTHON_PKGNAMEPREFIX}zope.testing>=3.7.1:${PORTSDIR}/devel/py-zope.testing \
		${PYTHON_PKGNAMEPREFIX}transaction>=1.1.0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zclockfile>=1.0.0:${PORTSDIR}/devel/py-zclockfile \
		${PYTHON_PKGNAMEPREFIX}zope.event>=1.0.0:${PORTSDIR}/devel/py-zope.event \
		${PYTHON_PKGNAMEPREFIX}zope.proxy>=3.4.2:${PORTSDIR}/net/py-zope.proxy
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	ZODB3
.include <bsd.port.mk>
