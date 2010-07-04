# New ports collection makefile for:	squeezeboxserver-dynamicplaylist
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dynamicplaylist
PORTVERSION=	2.8.2
CATEGORIES=	audio
MASTER_SITES=	http://erland.homeip.net/download/do/downloadapplication?name=slimserver-dynamicplaylist&filename=/
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	DynamicPlayList-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin to create dynamic playlists

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezeboxserver

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/DynamicPlayList
	${CP} -R ${WRKSRC}/DynamicPlayList/* ${PREFIX}/${SLIMDIR}/Plugins/DynamicPlayList

.include <bsd.port.mk>
