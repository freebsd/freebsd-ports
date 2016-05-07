# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-playback-status-plugin
DISTVERSION=	0.0.2015.09.12
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Playback status widget for DeaDBeeF audio player

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer
GH_PROJECT=	ddb_playback_status
GH_TAGNAME=	fce1de0

USES=		gmake pkgconfig

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK3

.for v in 2 3
GTK${v}_USE=	GNOME=gtk${v}0

GTK${v}_ALL_TARGET=	gtk${v}
GTK${v}_PLIST_FILES=	lib/deadbeef/ddb_misc_playback_status_GTK${v}.so

do-install-GTK${v}-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/deadbeef
	${INSTALL_LIB} ${WRKSRC}/gtk${v}/ddb_misc_playback_status_GTK${v}.so \
		${STAGEDIR}${PREFIX}/lib/deadbeef
.endfor

do-install:
	@${DO_NADA}

.include <bsd.port.mk>
