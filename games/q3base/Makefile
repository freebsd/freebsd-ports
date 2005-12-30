# New ports collection makefile for:	q3base
# Date created:				17 Nov 2005
# Whom:					Ed Schouten <ed@fxq.nl>
#
# $FreeBSD$
#

PORTNAME=		q3base
PORTVERSION=		0.1
CATEGORIES=		games
MASTER_SITES=		http://quake3.quakesrc.org/files/quake3/q3base/
PKGNAMEPREFIX=		quake3-

MAINTAINER=		ed@fxq.nl
COMMENT=		Quake III Arena fork using SDL

BUILD_DEPENDS=		nasm:${PORTSDIR}/devel/nasm

USE_BZIP2=		yes
USE_SDL=		sdl net

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		SDL_CONFIG=${SDL_CONFIG}
CONFIGURE_TARGET=
CONFLICTS=		q3server-1.32* quake3-[0-9]*

SUB_FILES=		pkg-message
PKGMESSAGE=		${WRKSRC}/pkg-message

.if defined(WITHOUT_X11)
CONFIGURE_ARGS=		--disable-client
.else
USE_GL=			yes
USE_SDL+=		image
.endif

.include <bsd.port.pre.mk>

post-install:
	@${MKDIR} ${PREFIX}/share/quake3/baseq3
	@${MKDIR} ${PREFIX}/share/quake3/missionpack
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
