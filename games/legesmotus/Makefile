# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	legesmotus
PORTVERSION=	0.4.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	A team-based, networked, 2D shooter set in zero-gravity

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--datadir="${DATADIR}"
USE_GMAKE=	yes
MAKE_ENV=	XDIR=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT SERVER METASERVER SERVERSCANNER
OPTIONS_DEFAULT=CLIENT SERVER
CLIENT_DESC=	Build client
SERVER_DESC=	Build server
METASERVER_DESC=Build metaserver
SERVERSCANNER_DESC=Build server scanner

DESKTOP_ENTRIES="Leges Motus" \
		"A team-based, networked, 2D shooter set in zero-gravity" \
		"${DATADIR}/sprites/blue_head32.png" \
		"legesmotus" \
		"Game;ActionGame;" \
		false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
PLIST_SUB+=	CLIENT=""
USE_SDL=	sdl image ttf mixer
USE_GL=		gl
MAN6+=		legesmotus.6
.else
PLIST_SUB+=	CLIENT="@comment "
CONFIGURE_ARGS+=--disable-client
.endif

.if ${PORT_OPTIONS:MSERVER}
PLIST_SUB+=	SERVER=""
MAN6+=		lmserver.6
.else
PLIST_SUB+=	SERVER="@comment "
CONFIGURE_ARGS+=--disable-server
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSERVER} || ${PORT_OPTIONS:MMETASERVER}
PLIST_SUB+=	DATA=""
.else
PLIST_SUB+=	DATA="@comment "
.endif

.if ${PORT_OPTIONS:MMETASERVER}
PLIST_SUB+=	METASERVER=""
CONFIGURE_ARGS+=--enable-metaserver
.else
PLIST_SUB+=	METASERVER="@comment "
.endif

.if ${PORT_OPTIONS:MSERVERSCANNER}
PLIST_SUB+=	SERVERSCANNER=""
CONFIGURE_ARGS+=--enable-serverscanner
MAN6+=		lmscan.6
.else
PLIST_SUB+=	SERVERSCANNER="@comment "
.endif

.include <bsd.port.mk>
