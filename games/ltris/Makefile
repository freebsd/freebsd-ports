# New ports collection makefile for:	ltris
# Date created:				19 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ltris
PORTVERSION=	1.0.7
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

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|"SDL/SDL|"SDL|g ; \
		 s|<SDL/SDL|<SDL|g'
	@${REINPLACE_CMD} -e 's|--mode=666||g' ${WRKSRC}/src/Makefile.in

post-install:
	${CHOWN} root:games ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 2755 ${PREFIX}/bin/${PORTNAME}
	${CHMOD} 664 ${PREFIX}/var/ltris.hscr
	${CHOWN} root:games ${PREFIX}/var/ltris.hscr

.include <bsd.port.post.mk>
