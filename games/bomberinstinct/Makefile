# New ports collection makefile for:	bomberinstinct
# Date created:				28 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bomberinstinct
PORTVERSION=	0.8.7
CATEGORIES=	games
MASTER_SITES=	http://harpe.dptmaths.ens-cachan.fr/U/gesbert/dl/
DISTNAME=	BomberInstinct-${PORTVERSION}

MAINTAINER=	sobomax@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

WRKSRC=		${WRKDIR}/${DISTNAME}

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

pre-patch:
	@find ${WRKSRC} -name "*.[ch]" | xargs ${PERL} -pi -e 's|<SDL/|<|g'

.include <bsd.port.mk>
