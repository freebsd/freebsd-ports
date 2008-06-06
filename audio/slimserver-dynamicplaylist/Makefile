# New ports collection makefile for:	slimserver-dynamicplaylist
# Date created:		28 October 2007
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dynamicplaylist
PORTVERSION=	1.14
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://erland.homeip.net/download/do/downloadapplication?name=slimserver-dynamicplaylist&filename=/
PKGNAMEPREFIX=	slimserver-
DISTNAME=	DynamicPlayList-${PORTVERSION}
DIST_SUBDIR=	slimserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SlimServer plugin to create dynamic playlists

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/slimserver

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USE_ZIP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/DynamicPlayList

SLIMDIR?=	slimserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/DynamicPlayList
	${CP} -R ${WRKSRC}/* ${PREFIX}/${SLIMDIR}/Plugins/DynamicPlayList

.include <bsd.port.mk>
