# New ports collection makefile for:	xmoto
# Date created:		07 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	xmoto
PORTVERSION=	0.2.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Challenging 2D motocross platform game

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_LUA=	5.1
USE_SDL=	sdl mixer
USE_DOS2UNIX=	src/*.cpp src/*.h

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include -I${LUA_INCDIR}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog

OPTIONS=	CURL	"Online high-scores and new levels download support"	on

.include <bsd.port.pre.mk>

.if defined(WITH_CURL)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/||; s|endian.h|sys/endian.h|' \
		${WRKSRC}/src/VCommon.h
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/image/tim_memory_crt.cpp
	@${REINPLACE_CMD} -e \
		'/LIBS/ s|\(-lSDL_mixer\)|`${SDL_CONFIG} --libs` \1| ; \
		 s|test $$ac_cv_lib_curl_curl_easy_init = yes|false|' \
		${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
