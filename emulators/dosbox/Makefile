# New ports collection makefile for:   dosbox
# Date created:        28 July 2002
# Whom:                Tom Carrick <knyghtmare@knyghtmare.com>
#
# $FreeBSD$
#

PORTNAME=	dosbox
PORTVERSION=	0.58
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	knyghtmare@knyghtmare.com
COMMENT=	An emulator of a PC with DOS

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's#"SDL.h"#<SDL11/SDL.h>#' \
		${WRKSRC}/src/gui/sdlmain.cpp ${WRKSRC}/src/hardware/mixer.cpp
	@${REINPLACE_CMD} -e 's#<SDL.h>#<SDL11/SDL.h>#' ${WRKSRC}/include/timer.h
	@${REINPLACE_CMD} -e 's#"SDL_thread.h"#<SDL11/SDL_thread.h>#' \
		${WRKSRC}/src/gui/sdlmain.cpp

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dosbox ${PREFIX}/bin/dosbox
	${MKDIR} ${PREFIX}/share/dosbox
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${WRKSRC}/NEWS ${PREFIX}/share/doc/dosbox
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/dosbox
.endif

post-install:
	@${ECHO_CMD} "================================================="
	@${ECHO_CMD} "Be sure to read the README for usage instructions"
	@${ECHO_CMD} "located in ${PREFIX}/share/doc/dosbox by default"
	@${ECHO_CMD} "================================================="

.include <bsd.port.mk>
