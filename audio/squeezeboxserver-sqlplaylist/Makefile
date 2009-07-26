# New ports collection makefile for:	squeezecenter-sqlplaylist
# Date created:		21 June 2008
# Whom:			Tim Bishop <tdb@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sqlplaylist
PORTVERSION=	2.4
CATEGORIES=	audio
MASTER_SITES=	http://erland.homeip.net/download/do/downloadapplication?name=slimserver-sqlplaylist&filename=/
PKGNAMEPREFIX=	squeezecenter-
DISTNAME=	SQLPlayList-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	squeezecenter

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	SqueezeCenter plugin to create playlists based on SQL queries

RUN_DEPENDS=	softsqueeze:${PORTSDIR}/audio/squeezecenter \
		${LOCALBASE}/${SLIMDIR}/Plugins/DynamicPlayList/install.xml:${PORTSDIR}/audio/squeezecenter-dynamicplaylist

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USE_ZIP=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SLIMDIR?=	squeezecenter
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList
	${CP} -R ${WRKSRC}/SQLPlayList/* ${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList

.include <bsd.port.mk>
