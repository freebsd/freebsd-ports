# New ports collection makefile for:	libuta
# Date created:				29 March 2001
# Whom:					Oliver Lehmann <lehmann@ans-netz.de>
#
# $FreeBSD$
#

PORTNAME=	libuta
PORTVERSION=	0.3.36
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lehmann@ans-netz.de

LIB_DEPENDS=    png.4:${PORTSDIR}/graphics/png \
		ttf.4:${PORTSDIR}/print/freetype \
		sigc.1:${PORTSDIR}/devel/libsigc++ \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

USE_LIBTOOL=	YES
CONFIGURE_ARGS=	--prefix=${PREFIX}

.include <bsd.port.mk>
