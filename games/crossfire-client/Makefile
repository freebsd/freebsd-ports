# New ports collection makefile for:	crossfire-client
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	crossfire-client
PORTVERSION=	1.8.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF/crossfire/${PORTNAME}/${PORTVERSION} \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-images-1.7.1${EXTRACT_SUFX} \
		${PORTNAME}-sounds-1.4.0${EXTRACT_SUFX}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Multiplayer graphical arcade and adventure game made for X11

USE_PERL5=	yes
USE_XORG=	xpm
WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_SDL=	image sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-sound-dir=${DATADIR}/sounds

MAN6=		cfclient.6

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/cfclient \
		bin/cfsndserv
.if ${HAVE_GNOME:Mgtk20}!="" || ${HAVE_GNOME:Mgtk12}!=""
MAN6+=		gcfclient.6
.if ${HAVE_GNOME:Mgtk20}!=""
USE_GNOME+=	gtk20
PLIST_FILES+=bin/gcfclient2
.endif
.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PLIST_FILES+=bin/gcfclient
.endif
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

PLIST_DIRS=	%%DATADIR%%/sounds \
		%%DATADIR%%
PLIST_FILES+=	%%DATADIR%%/bmaps.client \
		%%DATADIR%%/crossfire.base \
		%%DATADIR%%/crossfire.clsc \
		%%DATADIR%%/sounds/README \
		%%DATADIR%%/sounds/Creaky-1.raw \
		%%DATADIR%%/sounds/Evil_Laugh.raw \
		%%DATADIR%%/sounds/Explosion.raw \
		%%DATADIR%%/sounds/FloorTom.raw \
		%%DATADIR%%/sounds/Gun-5.raw \
		%%DATADIR%%/sounds/MetalCrash.raw \
		%%DATADIR%%/sounds/Missed.raw \
		%%DATADIR%%/sounds/Missle1.raw \
		%%DATADIR%%/sounds/Puke.raw \
		%%DATADIR%%/sounds/Tear.raw \
		%%DATADIR%%/sounds/Teeswing.raw \
		%%DATADIR%%/sounds/TowerClock.raw \
		%%DATADIR%%/sounds/Whoosh.raw \
		%%DATADIR%%/sounds/blip.raw \
		%%DATADIR%%/sounds/boink2.raw \
		%%DATADIR%%/sounds/bugle_charge.raw \
		%%DATADIR%%/sounds/chord.raw \
		%%DATADIR%%/sounds/click1.raw \
		%%DATADIR%%/sounds/click2.raw \
		%%DATADIR%%/sounds/drip.raw \
		%%DATADIR%%/sounds/first_try.raw \
		%%DATADIR%%/sounds/gong.raw \
		%%DATADIR%%/sounds/lightning1.raw \
		%%DATADIR%%/sounds/magic.raw \
		%%DATADIR%%/sounds/ouch1.raw \
		%%DATADIR%%/sounds/phit2.raw \
		%%DATADIR%%/sounds/sci_fi_gun.raw \
		%%DATADIR%%/sounds/squish.raw \
		%%DATADIR%%/sounds/swish.raw \

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/bmaps.client ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crossfire.base ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crossfire.clsc ${DATADIR}
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKDIR}/sounds/README ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKDIR}/sounds/*.raw ${DATADIR}/sounds

.include <bsd.port.post.mk>
