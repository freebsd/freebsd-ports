# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games/Makefile,v 1.139 2007/03/13 17:05:22 mezz Exp $
#

PORTNAME=	gnome-games
PORTVERSION=	2.18.1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the GNOME 2 Desktop Environment

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui \
		librsvg2 desktopfileutils pygnomedesktop gnomedocutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	aisleriot.schemas blackjack.schemas glchess.schemas \
		glines.schemas gnect.schemas gnibbles.schemas \
		gnobots2.schemas gnometris.schemas gnomine.schemas \
		gnotravex.schemas gnotski.schemas gtali.schemas \
		iagno.schemas libgnomegames.schemas mahjongg.schemas \
		same-gnome.schemas

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]*

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libavahi-client.a) || defined(WITH_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|share|share/gnome|g ; \
	    	s|/usr/local|${PREFIX}|g' \
	    	${WRKSRC}/gnome-sudoku/src/lib/defaults.py.in \
		${WRKSRC}/glchess/src/lib/defaults.py.in
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share/gnome|' \
		${WRKSRC}/gnome-sudoku/src/gnome-sudoku \
		${WRKSRC}/glchess/src/glchess \
		${WRKSRC}/gnome-sudoku/src/lib/dialog_swallower.py \
		${WRKSRC}/gnome-sudoku/src/lib/game_selector.py

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
