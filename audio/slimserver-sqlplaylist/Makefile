# New ports collection makefile for:	slimserver-sqlplaylist
# Date created:		28 October 2007
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlplaylist
PORTVERSION=	1.21
CATEGORIES=	audio
MASTER_SITES=	http://erland.homeip.net/download/do/downloadapplication?name=slimserver-sqlplaylist&filename=/
PKGNAMEPREFIX=	slimserver-
DISTNAME=	SQLPlayList-${PORTVERSION}
DIST_SUBDIR=	slimserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SlimServer plugin to create playlists based on SQL queries

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/slimserver \
		${LOCALBASE}/${SLIMDIR}/Plugins/DynamicPlayList/Plugin.pm:${PORTSDIR}/audio/slimserver-dynamicplaylist

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/SQLPlayList

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList
	${CP} -R ${WRKSRC}/* ${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList

.include <bsd.port.mk>
