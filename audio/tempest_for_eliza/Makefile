# New ports collection makefile for:   tempest_for_eliza
# Date created:        17 February 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=       tempest_for_eliza
PORTVERSION=	1.0.5
CATEGORIES=     audio
MASTER_SITES=   http://www.erikyyy.de/tempest/

MAINTAINER=	greid@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-install:
	${MKDIR} ${PREFIX}/share/tempest
.for S in forelise jonny fruehling saints oldmacdonald ungarian
	${INSTALL_DATA} ${WRKSRC}/songs/$S ${PREFIX}/share/tempest
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/tempest
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/tempest
.endif

.include <bsd.port.mk>
