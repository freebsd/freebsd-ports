# New ports collection makefile for:	columns
# Date created:				26 August 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	columns
PORTVERSION=	1.2b
CATEGORIES=	games
MASTER_SITES=	http://www.rzuser.uni-heidelberg.de/~dheck/columns/
DISTNAME=	Columns-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/columns
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/columns
.endif

.include <bsd.port.mk>
