# New ports collection makefile for:	asc
# Date created:				16 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asc
PORTVERSION=	1.3.21
CATEGORIES=	games
MASTER_SITES=	ftp://asc-hq.sourceforge.net/pub/asc-hq/develop/ \
		http://www.asc-hq.org/develop/
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta.src

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		gnugetopt.1:${PORTSDIR}/devel/libgnugetopt
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-beta

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LIBS="`${SDL_CONFIG} --libs` -lgnugetopt -lm"

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name "*.cpp" -or -name "*.h" \) | xargs \
		${PERL} -pi -e 's|malloc\.h|stdlib.h|g'

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
