# New ports collection makefile for:	squeezecenter-transitionupdater
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transitionupdater
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.sutula.us/james/slimserver/${PORTNAME}_${PORTVERSION}/
PKGNAMEPREFIX=	squeezecenter-
DISTNAME=	TransitionUpdater${PORTVERSION}
DIST_SUBDIR=	squeezecenter

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SqueezeCenter plugin for determining transitions between tracks

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezecenter

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezecenter
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/TransitionUpdater
	${CP} -R ${WRKSRC}/TransitionUpdater/* ${PREFIX}/${SLIMDIR}/Plugins/TransitionUpdater

.include <bsd.port.mk>
