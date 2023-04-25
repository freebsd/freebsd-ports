PORTNAME=	dynamicplaylist
PORTVERSION=	2.9.3853
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://downloads.isaksson.info/download/do/downloadapplication?name=slimserver-dynamicplaylist&filename=/
PKGNAMEPREFIX=	logitechmediaserver-
DISTNAME=	DynamicPlayList-${PORTVERSION:S/b/beta/}
DIST_SUBDIR=	logitechmediaserver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Logitech Media Server plugin to create dynamic playlists
WWW=		https://wiki.slimdevices.com/index.php/Dynamic_Playlist_plugin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/DynamicPlayList/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/${SLIMDIR}/slimserver.pl:audio/logitechmediaserver

FETCH_BEFORE_ARGS=	-o ${DISTFILES}
USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

SLIMDIR?=	share/logitechmediaserver
PLIST_SUB+=	SLIMDIR=${SLIMDIR}

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/DynamicPlayList
	${CP} -R ${WRKSRC}/DynamicPlayList/* ${STAGEDIR}${PREFIX}/${SLIMDIR}/Plugins/DynamicPlayList

.include <bsd.port.mk>
