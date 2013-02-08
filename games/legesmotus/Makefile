# New ports collection makefile for:	legesmotus
# Date created:		16 Jul 2009
# Whom:			Dmitry Marakasov <amdmi3@FreeBSD.org>
#
# $FreeBSD$
#

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

PORTDOCS=	*

OPTIONS=	CLIENT "Build client" on \
		SERVER "Build server" on \
		METASERVER "Build metaserver" off \
		SERVERSCANNER "Build server scanner" off

DESKTOP_ENTRIES="Leges Motus" \
		"A team-based, networked, 2D shooter set in zero-gravity" \
		"${DATADIR}/sprites/blue_head32.png" \
		"legesmotus" \
		"Game;ActionGame;" \
		false

.include <bsd.port.options.mk>

.if defined(WITHOUT_CLIENT)
PLIST_SUB+=	CLIENT="@comment "
CONFIGURE_ARGS+=--disable-client
.else
PLIST_SUB+=	CLIENT=""
USE_SDL=	sdl image ttf mixer
USE_GL=		gl
MAN6+=		legesmotus.6
.endif

.if defined(WITHOUT_SERVER)
PLIST_SUB+=	SERVER="@comment "
CONFIGURE_ARGS+=--disable-server
.else
PLIST_SUB+=	SERVER=""
MAN6+=		lmserver.6
.endif

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER) && defined(WITHOUT_METASERVER)
PLIST_SUB+=	DATA="@comment "
.else
PLIST_SUB+=	DATA=""
.endif

.if defined(WITH_METASERVER)
PLIST_SUB+=	METASERVER=""
CONFIGURE_ARGS+=--enable-metaserver
.else
PLIST_SUB+=	METASERVER="@comment "
.endif

.if defined(WITH_SERVERSCANNER)
PLIST_SUB+=	SERVERSCANNER=""
CONFIGURE_ARGS+=--enable-serverscanner
MAN6+=		lmscan.6
.else
PLIST_SUB+=	SERVERSCANNER="@comment "
.endif

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_SERVER) && defined(WITHOUT_METASERVER) && defined(WITHOUT_SERVERSCANNER)
IGNORE=		cannot be built with all components disabled. Please rerun 'make config' and enable at least one option
.endif

.include <bsd.port.mk>
