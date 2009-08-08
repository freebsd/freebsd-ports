# New ports collection makefile for:	py-aspyct
# Date created:		2009-08-07
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	aspyct
PORTVERSION=	3.0
CATEGORIES=	devel python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/a/A/}-${PORTVERSION}_beta_4

MAINTAINER=	sbrabez@gmail.com
COMMENT=	Python library including an aspect-oriented programming (AOP) engine

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	${DISTNAME}-py${PYTHON_VER}.egg-info

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
