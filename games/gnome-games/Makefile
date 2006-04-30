# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnomegames2/Makefile,v 1.111 2006/04/13 07:52:34 bland Exp $
#

PORTNAME=	gnomegames2
PORTVERSION=	2.14.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gnome-games/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DISTNAME=	gnome-games-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the Gnome 2 Desktop Environment

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui \
		librsvg2 desktopfileutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	aisleriot.schemas blackjack.schemas gataxx.schemas \
		glines.schemas gnect.schemas gnibbles.schemas \
		gnobots2.schemas gnometris.schemas gnomine.schemas \
		gnotravex.schemas gnotski.schemas gtali.schemas \
		iagno.schemas libgnomegames.schemas mahjongg.schemas \
		same-gnome.schemas

CONFLICTS=	sol-1.0.*

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libavahi-client.a) || defined(WITH_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|malloc\.h|stdlib.h|g'
	@${REINPLACE_CMD} -e 's|bin/python|bin/env python|g' \
		${WRKSRC}/libgames-support/games-server.py
	@${REINPLACE_CMD} -e 's|howl|avahi-compat-howl|' \
		${WRKSRC}/configure
#	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
#		's|664|666|g ; \
#		 s|2555|0555|g'

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
