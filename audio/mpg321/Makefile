# ex:ts=8
# New ports collection makefile for:	mpg321
# Date created:			Mar 17, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mpg321
PORTVERSION=	0.0.5
CATEGORIES=	audio
MASTER_SITES=	http://gemini.woot.net/~hosehead/packages/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

LIB_DEPENDS=	smpeg.1:${PORTSDIR}/graphics/smpeg \
		ao.1:${PORTSDIR}/audio/libao \
		SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib -lc_r -lgnugetopt" \
		CFLAGS="-I${LOCALBASE}/include" \
		SDL_CONFIG="${SDL_CONFIG}"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		mpg321.1

.include <bsd.port.mk>
