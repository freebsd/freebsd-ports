# New ports collection makefile for:	tuxtype
# Date created:				Mon Aug  6 21:53:03 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	tuxtype
PORTVERSION=	1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	pat@databits.net

LIB_DEPENDS=	SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

USE_X_PREFIX=	yes
USE_AUTOCONF=	yes
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

pre-patch:
.for dirs in data images sounds docs/en ..
	@${PERL} -pi.orig -e 's|${LOCALBASE}/share/tuxtype|${DATADIR}|; \
		s|/usr/doc/tuxtype|${DOCSDIR}|' \
		${WRKSRC}/tuxtype/${dirs}/Makefile.am
.endfor
.for files in graphics playgame
	@${PERL} -pi.orig -e 's|${LOCALBASE}/share/tuxtype|${DATADIR}|' \
		${WRKSRC}/tuxtype/${files}.h
.endfor

post-install:
.if defined(NOPORTDOCS)
	@${RM} -Rf ${DOCSDIR}
.endif

.include <bsd.port.mk>
