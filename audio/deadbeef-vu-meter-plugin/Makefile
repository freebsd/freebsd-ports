# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	deadbeef-vu-meter-plugin
DISTVERSION=	0.0.2014.09.14
CATEGORIES=	audio

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	VU meter plugin for DeaDBeeF audio player

BUILD_DEPENDS=	${LOCALBASE}/include/deadbeef/deadbeef.h:audio/deadbeef
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes
GH_ACCOUNT=	cboxdoerfer
GH_PROJECT=	ddb_vu_meter
GH_TAGNAME=	940d8d7

USES=		gmake gnome pkgconfig

MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	share/deadbeef/pixmaps/vumeter.png

OPTIONS_DEFINE=	GTK2 GTK3
OPTIONS_DEFAULT=	GTK2

.for v in 2 3
GTK${v}_USE=	GNOME=gtk${v}0

GTK${v}_ALL_TARGET=	gtk${v}
GTK${v}_PLIST_FILES=	lib/deadbeef/ddb_vis_vu_meter_GTK${v}.so

do-install-GTK${v}-on:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/deadbeef
	${INSTALL_LIB} ${WRKSRC}/gtk${v}/ddb_vis_vu_meter_GTK${v}.so \
		${STAGEDIR}${PREFIX}/lib/deadbeef
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/deadbeef/pixmaps
	${INSTALL_DATA} ${WRKSRC}/vumeter.png \
		${STAGEDIR}${PREFIX}/share/deadbeef/pixmaps

.include <bsd.port.mk>
