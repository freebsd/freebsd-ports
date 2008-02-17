# New ports collection makefile for:	xmoto
# Date created:		07 Oct 2005
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	xmoto
PORTVERSION=	0.4.1
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/xmoto/xmoto/${PORTVERSION}/ \
		http://www.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Challenging 2D motocross platform game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		curl.4:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	${X11BASE}/lib/libode.a:${PORTSDIR}/devel/ode

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LUA=	5.1
USE_SQLITE=	yes
USE_SDL=	sdl mixer ttf
USE_DOS2UNIX=	src/*.cpp src/*.h

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include -I${LUA_INCDIR}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -L${LUA_LIBDIR}
MANCOMPRESSED=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog

OPTIONS=	ZOOM	"Enable zooming"	on \
		SDL_GFX	"Use sdl_gfx rendering instead of OpenGL (broken)"	off

MAN6=		xmoto.6

.include <bsd.port.pre.mk>

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
	@${REINPLACE_CMD} -e '/LIBS/ s|-lSDL_mixer|`${SDL_CONFIG} --libs` &|' \
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
