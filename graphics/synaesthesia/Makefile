# New ports collection makefile for:	synaesthesia
# Date created:				25 May 2001
# Whom:					petef@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	synaesthesia
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.logarithmic.net/pfh/Synaesthesia/

MAINTAINER=	petef@FreeBSD.org
COMMENT=	Graphically represents sound in real time

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	Yes
USE_REINPLACE=	Yes
USE_X_PREFIX=	Yes

GNU_CONFIGURE=	Yes
CONFIGURE_ARGS=	--with-sdl-prefix=${LOCALBASE}
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

post-patch:
	@${REINPLACE_CMD} -e 's,stdint.h,inttypes.h,' `${FIND} ${WRKSRC} -name \*.cc -or -name \*.c`
	@${REINPLACE_CMD} -e 's,int16_t,u_int16_t,' \
		-e 's,machine/soundcard.h,sys/soundcard.h,' ${WRKSRC}/sound.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/synaesthesia ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/synaesthesia
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/synaesthesia
.endif

.include <bsd.port.mk>
