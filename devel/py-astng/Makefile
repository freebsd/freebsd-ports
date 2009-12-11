# New ports collection makefile for:	astng
# Date created:		27 Apr 2006
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	astng
PORTVERSION=	0.19.1
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	LOGILAB
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	logilab-${PORTNAME}-${PORTVERSION}

MAINTAINER=	mva@FreeBSD.org
COMMENT=	Extension for Python compiler.ast module

RUN_DEPENDS=	pytest:${PORTSDIR}/devel/py-logilab-common

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	logilab-astng

.include <bsd.port.mk>
