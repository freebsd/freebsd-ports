# New ports collection makefile for:	gnomegames2
# Date created:				08 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/games/gnome-games/Makefile,v 1.206 2009/10/20 10:40:07 avl Exp $
#

PORTNAME=	gnome-games
PORTVERSION=	2.28.2
CATEGORIES=	games gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The game applications package for the GNOME 2 Desktop Environment

LIB_DEPENDS=	guile.20:${PORTSDIR}/lang/guile \
		clutter-gtk-0.10.0:${PORTSDIR}/graphics/clutter-gtk \
		clutter-glx-1.0.0:${PORTSDIR}/graphics/clutter \
		ggzmod.5:${PORTSDIR}/games/ggz-client-libs

USE_BZIP2=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeui \
		librsvg2 desktopfileutils pygnomedesktop gnomedocutils
USE_GSTREAMER=	vorbis ogg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-sound=gstreamer \
		--disable-tests \
		--enable-introspection=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	aisleriot.schemas blackjack.schemas glchess.schemas \
		glines.schemas gnect.schemas gnibbles.schemas \
		gnobots2.schemas gnome-sudoku.schemas gnometris.schemas \
		gnomine.schemas gnotravex.schemas gnotski.schemas \
		gtali.schemas iagno.schemas mahjongg.schemas same-gnome.schemas

CONFLICTS=	sol-1.0.* glchess-[0-9]* gnomesudoku-[0-9]*

DSC_FILES=	iagno/iagno-client.dsc gnect/data/gnect-client.dsc \
		gnibbles/gnibbles-client.dsc

MAN6=		blackjack.6 glchess.6 glines.6 gnect.6 gnibbles.6 gnobots2.6 \
		gnome-sudoku.6 gnometris.6 gnomine.6 gnotravex.6 gnotski.6 \
		gtali.6 iagno.6 mahjongg.6 same-gnome.6 sol.6

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libavahi-client.a) || defined(WITH_MDNS)
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' \
	    	${WRKSRC}/gnome-sudoku/src/lib/defaults.py.in \
		${WRKSRC}/glchess/src/lib/defaults.py.in

post-install:
	${MKDIR} ${PREFIX}/share/ggz/gnome-games
.for dsc in ${DSC_FILES}
	${INSTALL_DATA} ${WRKSRC}/${dsc} ${PREFIX}/share/ggz/gnome-games/${dsc:T}
.endfor
	@-update-desktop-database

.include <bsd.port.post.mk>
