# New ports collection makefile for:	crossfire-client
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	crossfire-client
PORTVERSION=	1.7.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/
MASTER_SITE_SUBDIR=	${PORTNAME:S/-client//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-images-1.5.0${EXTRACT_SUFX} \
		${PORTNAME}-sounds-1.4.0${EXTRACT_SUFX}

MAINTAINER=	ports@mark.reidel.info
COMMENT=	Multiplayer graphical arcade and adventure game made for X11

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_XPM=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-sound-dir=${DATADIR}/sounds

OPTIONS=	SDL "Use SDL for images" on

MAN1=		cfclient.1

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
MAN1+=		gcfclient.1
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl
.else
USE_SDL=	image sdl
.endif

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/bmaps.client ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crossfire.base ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crossfire.clsc ${DATADIR}
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKDIR}/sounds/README ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKDIR}/sounds/*.raw ${DATADIR}/sounds

.include <bsd.port.post.mk>
