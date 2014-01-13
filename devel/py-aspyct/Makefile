# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	aspyct
PORTVERSION=	3.0
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}%20beta%204
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:C/a/A/}-${PORTVERSION}_beta_4

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python library including an aspect-oriented programming (AOP) engine

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFO=	${DISTNAME}-py${PYTHON_VER}.egg-info

NO_STAGE=	yes
post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
