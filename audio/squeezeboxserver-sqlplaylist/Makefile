# New ports collection makefile for:	squeezeboxserver-sqlplaylist
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlplaylist
PORTVERSION=	2.5.3359
CATEGORIES=	audio
MASTER_SITES=	http://erland.isaksson.info/download/do/downloadapplication?name=slimserver-sqlplaylist&filename=/
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	SQLPlayList-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin to create playlists based on SQL queries

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezeboxserver \
		${LOCALBASE}/${SLIMDIR}/Plugins/DynamicPlayList/install.xml:${PORTSDIR}/audio/squeezeboxserver-dynamicplaylist

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList
	${CP} -R ${WRKSRC}/SQLPlayList/* ${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList

.include <bsd.port.mk>
