# New ports collection makefile for:	asc
# Date created:				16 February 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	asc
PORTVERSION=	1.3.13
CATEGORIES=	games
MASTER_SITES=	ftp://asc-hq.sourceforge.net/pub/asc-hq/develop/ \
		ftp://asc-hq.sourceforge.net/pub/asc-hq/ \
		http://www.asc-hq.org/develop/ \
		http://www.asc-hq.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-beta.src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DATAFILE}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		bz2.1:${PORTSDIR}/archivers/bzip2

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-beta

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="`${SDL_CONFIG} --cflags`" \
		LIBS="`${SDL_CONFIG} --libs` -lm"

DATAFILE=	main.con

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	@find ${WRKSRC} \( -name "*.cpp" -or -name "*.h" \) | xargs \
		${PERL} -pi -e 's|malloc\.h|stdlib.h|g'

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

post-install:
	${MKDIR} ${PREFIX}/share/asc
	${INSTALL_DATA} ${DISTDIR}/${DATAFILE} ${PREFIX}/share/asc

.include <bsd.port.mk>
