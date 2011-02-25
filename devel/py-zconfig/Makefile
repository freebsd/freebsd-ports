# New ports collection makefile for:	py-zconfig
# Date created:		8 September 2005
# Whom:			Landon Fuller <landonf@opendarwin.org>
#
# $FreeBSD$

PORTNAME=	zconfig
PORTVERSION=	2.8.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP \
		http://www.zope.org/Members/fdrake/zconfig/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ZConfig-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	ZConfig is a general use python configuration library

WRKSRC=		${WRKDIR}/ZConfig-${PORTVERSION}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	easy_install

PYDISTUTILS_PKGNAME=	ZConfig

.include <bsd.port.mk>
