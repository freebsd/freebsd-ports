# ex:ts=8
# New ports collection makefile for:	ksmp3play
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	ksmp3play
PORTVERSION=	0.5.1
CATEGORIES=	audio
MASTER_SITES=	http://www.xanadunet.net/ksmp3play/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	An curses-based MP3 player

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		smpeg:${PORTSDIR}/graphics/smpeg \
		gnugetopt:${PORTSDIR}/devel/libgnugetopt

USE_REINPLACE=	yes
SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${SDL_CONFIG} \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
MAN1=	ksmp3play.1

post-patch:
	@${REINPLACE_CMD} -e "s,-lpthread,${PTHREAD_LIBS},g" ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ksmp3play* ${DOCSDIR}
.endif

.include <bsd.port.mk>
