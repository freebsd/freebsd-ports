#
# Ports collection makefile for:	scorched3d
# Date created:				Jan 5, 2003
# Whom:					mdodd
#
# $FreeBSD$

PORTNAME=	scorched3d
PORTVERSION=	0.32.0
CATEGORIES=	games
MASTER_SITES=	http://users.pandora.be/redzebra/
PKGNAMESUFFIX=	devel
DISTNAME=	scorched3d-${PORTVERSION}

PATCH_SITES=	ftp://ftp.jurai.net/users/winter/patches/
PATCHFILES=	scorched3d-0.32.0-FreeBSD.patch.0.gz

MAINTAINER=	mdodd@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_MESA=	yes
HAS_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--prefix=${PREFIX}/games
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
			SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"
MAKE_ENV=		SDL_CONFIG="${LOCALBASE}/bin/sdl11-config"

pre-install:
	@mkdir -p ${PREFIX}/games
post-install:
	@ln -fs ${PREFIX}/games/scorched3d/scorched3d ${PREFIX}/bin/scorched3d

.include <bsd.port.mk>
