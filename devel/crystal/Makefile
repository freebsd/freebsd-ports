# New ports collection makefile for:   crystal
# Date created:        Thu Feb 21 18:44:14 CST 2002
# Whom:                Kyle Martin
#
# $FreeBSD$
#

PORTNAME=	crystal
PORTVERSION=	0.92
CATEGORIES=	devel
MASTER_SITES=	ftp://sunsite.dk/projects/crystal/cs092/source/
DISTNAME=	cs92_001

MAINTAINER=	mkm@ieee.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_net.0:${PORTSDIR}/net/sdl_net

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/CS

pre-build:
	cd ${WRKSRC}; ${GMAKE} freebsd

.include <bsd.port.mk>
