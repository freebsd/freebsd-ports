# New ports collection makefile for:	pengpong
# Date created:				Fri Aug 24 18:21:25 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	pengpong
PORTVERSION=	0.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@databits.net

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

NO_WRKSUBDIR=	yes
MAKE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

do-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/pengpong ${PREFIX}/bin

.include <bsd.port.mk>
