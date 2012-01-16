# New ports collection makefile for:	py-Products.MIMETools
# Date created:				Nov 15, 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	Products.MIMETools
PORTVERSION=	2.13.0
CATEGORIES=	devel python zope
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DIST_SUBDIR=	zope

MAINTAINER=	zope@FreeBSD.org
COMMENT=	Provides the <!--#mime--> tag for DocumentTemplate

LICENSE=	ZPL21

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}DocumentTemplate>=0:${PORTSDIR}/devel/py-DocumentTemplate

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
USE_ZIP=	yes

.include <bsd.port.mk>
