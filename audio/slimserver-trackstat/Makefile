# New ports collection makefile for:	slimserver-trackstat
# Date created:		28 October 2007
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trackstat
PORTVERSION=	1.40.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://erland.homeip.net/download/do/downloadapplication?name=slimserver-trackstat&filename=/
PKGNAMEPREFIX=	slimserver-
DISTNAME=	TrackStat-${PORTVERSION}
DIST_SUBDIR=	slimserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SlimServer plugin to store ratings and statistics about songs

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/slimserver

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/TrackStat

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/TrackStat
	${CP} -R ${WRKSRC}/* ${PREFIX}/${SLIMDIR}/Plugins/TrackStat

.include <bsd.port.mk>
