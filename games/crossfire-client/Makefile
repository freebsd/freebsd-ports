# New ports collection makefile for:	crossfire-client
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	crossfire-client
PORTVERSION=	1.5.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/
MASTER_SITE_SUBDIR=	${PORTNAME:S/-client//}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-images-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-sounds-1.4.0${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multiplayer graphical arcade and adventure game made for X11

USE_X_PREFIX=	yes
USE_PERL5=	yes
USE_XPM=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_AUTOCONF_VER=	253
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--with-sound-dir=${DATADIR}/sounds \
		--disable-gnome # Gnome client currently broken

MAN1=		cfclient.1 gcfclient.1

.if defined(WITHOUT_SDL)
CONFIGURE_ARGS+=	--disable-sdl
.else
LIB_DEPENDS+=	SDL_image.10:${PORTSDIR}/graphics/sdl_image
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}"
.endif

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/bmaps.client ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crossfire.base ${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/crossfire.clsc ${DATADIR}
	@${MKDIR} ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKDIR}/sounds/README ${DATADIR}/sounds
	${INSTALL_DATA} ${WRKDIR}/sounds/*.raw ${DATADIR}/sounds

.include <bsd.port.mk>
