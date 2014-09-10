# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	legesmotus
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Team-based, networked, 2D shooter set in zero-gravity

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix="${PREFIX}" \
		--mandir="${PREFIX}/man" \
		--datadir="${DATADIR}"
USES=		gmake
MAKE_ENV=	XDIR=${LOCALBASE}

PORTDATA=	*

OPTIONS_MULTI=	COMPONENTS
OPTIONS_MULTI_COMPONENTS=CLIENT SERVER METASERVER SERVERSCANNER
OPTIONS_DEFAULT=CLIENT SERVER
OPTIONS_SUB=	yes

CLIENT_DESC=	Build client
SERVER_DESC=	Build server
METASERVER_DESC=Build metaserver
SERVERSCANNER_DESC=Build server scanner

CLIENT_CONFIGURE_OFF=		--disable-client
SERVER_CONFIGURE_OFF=		--disable-server
METASERVER_CONFIGURE_ON=	--enable-metaserver
SERVERSCANNER_CONFIGURE_ON=	--enable-serverscanner

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
USE_SDL=	sdl image ttf mixer
USE_GL=		gl

DESKTOP_ENTRIES="Leges Motus" \
		"A team-based, networked, 2D shooter set in zero-gravity" \
		"${DATADIR}/sprites/blue_head32.png" \
		"legesmotus" \
		"Game;ActionGame;" \
		""
.endif

.include <bsd.port.mk>
