# New ports collection makefile for: criticalmass
# Date created:		15 Sep 2003
# Whom:			benlutz@datacomm.ch
#
# $FreeBSD$
#

PORTNAME=	freedroid
PORTVERSION=	1.0.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freedroid

MAINTAINER=	benlutz@datacomm.ch
COMMENT=	Freedroid is a clone of the classic game "Paradroid"

LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg \
		png:${PORTSDIR}/graphics/png \
		vorbis.3:${PORTSDIR}/audio/libvorbis

USE_XLIB=	yes
USE_SDL=	mixer image sdl
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${X11BASE}/lib" \
		CPPFLAGS="${CFLAGS} -I${X11BASE}/include"
CONFIGURE_ARGS=	--program-transform-name=

MAN6=		freedroid.6

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's#sdl-config#sdl11-config#; s#-lSDL # #;' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#mac-osx ##;' ${WRKSRC}/Makefile.am ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's#\#include \"mac-osx/getopt\.h\"##;' ${WRKSRC}/src/system.h

.include <bsd.port.post.mk>
