# New ports collection makefile for:   gngb
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gngb
PORTVERSION=	20030809
CATEGORIES=	emulators
MASTER_SITES=	http://membres.lycos.fr/frogus/gngb/download/ \
		http://m.peponas.free.fr/gngb/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GameBoy(tm) emulator

USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GETOPT_LONG=yes
USE_XLIB=	yes
USE_X_PREFIX=	yes
CONFIGURE_ENV=	CFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib"
PORT_CFLAGS=	-DSDL_YUV -I${LOCALBASE}/include -I${LOCALBASE}/include/SDL11 -I${X11BASE}/include

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif
.if defined(WITH_GL)
CONFIGURE_ARGS=	--with-gl
PORT_CFLAGS+=	-DSDL_GL
.else
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable OpenGL support by defining WITH_GL"
	@${ECHO_MSG}
.endif

pre-configure:
	@${REINPLACE_CMD} -e 's|sdl-config|sdl11-config|g; \
		s|-lSDL|-lSDL-1.1|g; \
		s|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-configure:
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${REINPLACE_CMD} -e 's|\(CFLAGS =\).*|\1 ${PORT_CFLAGS} ${CFLAGS}|' ${WRKSRC}/src/Makefile
.endif

.include <bsd.port.mk>
