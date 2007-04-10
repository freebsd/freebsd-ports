# New ports collection makefile for:	xmoto
# Date created:		07 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	xmoto
PORTVERSION=	0.2.7
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/xmoto/xmoto/${PORTVERSION}/ \
		http://www.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Challenging 2D motocross platform game

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LUA=	5.1
USE_SDL=	sdl mixer
USE_DOS2UNIX=	src/*.cpp src/*.h
USE_GCC=	3.4+

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--mandir="${PREFIX}/man"
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include -I${LUA_INCDIR}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LUA_LIBDIR}
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog

OPTIONS=	WWW	"Online high-scores and new levels download support"	on \
		ZOOM	"Enable zooming"	off \
		SDL_GFX	"Use sdl_gfx rendering instead of OpenGL"	off

MAN6=		xmoto.6

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_WWW)
LIB_DEPENDS+=	curl.4:${PORTSDIR}/ftp/curl
CONFIGURE_ARGS+=	--with-enable-www=1
.else
CONFIGURE_ARGS+=	--with-enable-www=0
.endif

.if defined(WITH_ZOOM)
CONFIGURE_ARGS+=	--with-enable-zoom=1
.else
CONFIGURE_ARGS+=	--with-enable-zoom=0
.endif

.if defined(WITH_SDL_GFX)
USE_SDL+=	gfx
CONFIGURE_ARGS+=--with-renderer-sdlGfx=1 --with-renderer-openGl=0
.else
USE_GL=		yes
CONFIGURE_ARGS+=--with-renderer-sdlGfx=0 --with-renderer-openGl=1
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV+=	LIBS="-lintl"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/||; s|endian.h|sys/endian.h|' \
		${WRKSRC}/src/VCommon.h
	@${REINPLACE_CMD} -e 's|malloc.h|stdlib.h|' \
		${WRKSRC}/src/image/tim_memory_crt.cpp
	@${REINPLACE_CMD} -e \
		'/LIBS/ s|\(-lSDL_mixer\)|`${SDL_CONFIG} --libs` \1| ; \
		 s|function displayRequirement|displayRequirement()|; \
		 /Locales/ s|libc|libintl|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/mang|/man6|' ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
