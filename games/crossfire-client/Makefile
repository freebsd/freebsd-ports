# New ports collection makefile for:	crossfire-client
# Date created:         So  27 Okt 1996 12:25:55 MET
# Whom:                 Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	crossfire
PORTVERSION=	1.1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ifi.uio.no/pub/crossfire/ \
		ftp://ftp.real-time.com/pub/games/crossfire/
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-client
DISTFILES=	${PORTNAME}-client-${PORTVERSION}.tar.gz \
		${PORTNAME}-client-sounds-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		png.5:${PORTSDIR}/graphics/png

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

WRKSRC=		${WRKDIR}/${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}
USE_XPM=	yes
USE_GTK=	yes
USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"
CONFIGURE_ARGS=	--with-includes=-I${LOCALBASE}/include \
		--with-ldflags=-L${LOCALBASE}/lib \
		--with-sound-dir=${PREFIX}/share/cfclient/sounds \
		--disable-gnome # Gnome client currently broken

MAN1=		cfclient.1 gcfclient.1

post-install:
	@${MKDIR} ${PREFIX}/share/cfclient/sounds
	@${INSTALL_DATA} ${WRKDIR}/sounds/*.raw ${WRKDIR}/sounds/README \
		${PREFIX}/share/cfclient/sounds

.include <bsd.port.mk>
