# New ports collection makefile for: py-mnemosyne
# Date created:		11 Jan 2008
# Whom:			Beech Rintoul <beech@FreeBSD.org>
#
#
# $FreeBSD$
#

PORTNAME=	mnemosyne
PORTVERSION=	1.0
CATEGORIES=	games python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}-proj
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	mnemosyne-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	Flash-card tool which optimises your learning process

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PLIST_SUB+=	PYVER=${PYTHON_VERSION}

RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/pygame/__init__.py:${PORTSDIR}/devel/py-game

.include <bsd.port.mk>
