# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlplaylist
PORTVERSION=	2.5.3359
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://erland.isaksson.info/download/do/downloadapplication?name=slimserver-sqlplaylist&filename=/
PKGNAMEPREFIX=	squeezeboxserver-
DISTNAME=	SQLPlayList-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	squeezeboxserver

MAINTAINER=	tdb@FreeBSD.org
COMMENT=	Squeezebox Server plugin to create playlists based on SQL queries

RUN_DEPENDS=	softsqueeze:audio/squeezeboxserver \
		${LOCALBASE}/${SLIMDIR}/Plugins/DynamicPlayList/install.xml:audio/squeezeboxserver-dynamicplaylist

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	squeezeboxserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList
	${CP} -R ${WRKSRC}/SQLPlayList/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList

.include <bsd.port.mk>
