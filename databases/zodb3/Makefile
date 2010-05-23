# New ports collection makefile for:	zodb3
# Date created:		8 Dezember 2002
# Whom:			Martin Klaffenboeck <martin.klaffenboeck@gmx.at>
#
# $FreeBSD$
#

PORTNAME=	zodb
PORTVERSION=	3.9.4
CATEGORIES=	databases
MASTER_SITES=	CHEESESHOP
PKGNAMESUFFIX=	-py${PYTHON_SUFFIX}
DISTNAME=	ZODB3-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Z - Object Database for python

BUILD_DEPENDS=	${LOCALBASE}/bin/zconfig:${PORTSDIR}/devel/py-zconfig \
		${LOCALBASE}/bin/zdaemon:${PORTSDIR}/sysutils/py-zdaemon \
		${PYTHON_PKGNAMEPREFIX}zopeInterface>=3.3.0:${PORTSDIR}/devel/py-zopeInterface \
		${PYTHON_PKGNAMEPREFIX}zopetesting>=3.7.1:${PORTSDIR}/devel/py-zopetesting \
		${PYTHON_PKGNAMEPREFIX}transaction>=1.0.0:${PORTSDIR}/devel/py-transaction \
		${PYTHON_PKGNAMEPREFIX}zclockfile>=1.0.0:${PORTSDIR}/devel/py-zclockfile \
		${PYTHON_PKGNAMEPREFIX}zopeevent>=1.0.0:${PORTSDIR}/devel/py-zopeevent \
		${PYTHON_PKGNAMEPREFIX}zopeproxy>=3.4.2:${PORTSDIR}/net/py-zopeproxy
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	easy_install
PYEASYINSTALL_ARCHDEP=	yes
PYDISTUTILS_PKGNAME=	ZODB3
.include <bsd.port.mk>
