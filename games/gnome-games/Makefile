# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games/Makefile,v 1.120 2006/10/03 01:23:20 ahze Exp $
#

PORTNAME=	gnome-games
PORTVERSION=	2.16.3
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the Gnome 2 Desktop Environment

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui \
		librsvg2
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

#.if exists(${LOCALBASE}/lib/libavahi-client.a) || defined(WITH_MDNS)
#LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi
#.endif

post-patch:
	@${REINPLACE_CMD} -e 's|bin/python|bin/env python|g' \
		${WRKSRC}/libgames-support/games-server.py

.include <bsd.port.post.mk>
