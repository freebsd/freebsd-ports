# New ports collection makefile for:  	kyra
# Date created:				10.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	kyra
PORTVERSION=	2.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kyra
DISTNAME=	${PORTNAME}_src_2_0_5

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Kyra is a simple Sprite engine written in C++

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		jpeg.9:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/${PORTNAME}

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${X11BASE}/include"
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
