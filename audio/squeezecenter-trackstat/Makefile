# New ports collection makefile for:	squeezecenter-trackstat
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trackstat
PORTVERSION=	2.8
CATEGORIES=	audio
MASTER_SITES=	http://erland.homeip.net/download/do/downloadapplication?name=slimserver-trackstat&filename=/
PKGNAMEPREFIX=	squeezecenter-
DISTNAME=	TrackStat-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	squeezecenter

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SqueezeCenter plugin to store ratings and statistics about songs

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezecenter

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezecenter
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/TrackStat
	${CP} -R ${WRKSRC}/TrackStat/* ${PREFIX}/${SLIMDIR}/Plugins/TrackStat

.include <bsd.port.mk>
