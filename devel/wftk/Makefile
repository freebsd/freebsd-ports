# New ports collection makefile for:	libuta
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	libuta
PORTVERSION=	0.3.38
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=    png.5:${PORTSDIR}/graphics/png \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

USE_FREETYPE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/freetype1"

.include <bsd.port.mk>
