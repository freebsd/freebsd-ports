# New ports collection makefile for:	ltris
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ltris
PORTVERSION=	1.0.6
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An another tetris clone but a good one with bunch of cool features

USE_SDL=	mixer sdl
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|"SDL/SDL|"SDL|g ; \
		 s|<SDL/SDL|<SDL|g'

post-install:
	${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 664 /var/games/${PORTNAME}/ltris.hscr
	${CHOWN} root:games /var/games/${PORTNAME}/ltris.hscr

.include <bsd.port.mk>
