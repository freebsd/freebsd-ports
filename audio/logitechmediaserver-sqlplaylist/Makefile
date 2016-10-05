# Created by: Tim Bishop <tdb@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sqlplaylist
PORTVERSION=	2.5.3859
CATEGORIES=	audio
MASTER_SITES=	http://downloads.isaksson.info/download/do/downloadapplication?name=slimserver-sqlplaylist&filename=/
PKGNAMEPREFIX=	logitechmediaserver-
DISTNAME=	SQLPlayList-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	logitechmediaserver

MAINTAINER=	mark@tranquillussoftware.co.uk
COMMENT=	Logitech Media Server plugin to create playlists based on SQL queries

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/SQLPlayList/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/${SLIMDIR}/slimserver.pl:audio/logitechmediaserver \
		${LOCALBASE}/${SLIMDIR}/Plugins/DynamicPlayList/install.xml:audio/logitechmediaserver-dynamicplaylist

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	share/logitechmediaserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList
	${CP} -R ${WRKSRC}/SQLPlayList/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/SQLPlayList

.include <bsd.port.mk>
