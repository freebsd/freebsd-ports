# New ports collection makefile for:   gngb
# Date created:        16 April 2001
# Whom:                Yukihiro Nakai <nakai@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gngb
PORTVERSION=	20020111
CATEGORIES=	emulators
MASTER_SITES=	http://membres.lycos.fr/frogus/gngb/download/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	nakai@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
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
	@${PERL} -pi -e 's|sdl-config|sdl11-config|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|-lSDL|-lSDL-1.1|g' ${WRKSRC}/configure
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

post-configure:
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${PERL} -pi -e 's|(CFLAGS =).*|\1 ${PORT_CFLAGS} ${CFLAGS}|' ${WRKSRC}/src/Makefile
.endif

.include <bsd.port.mk>
