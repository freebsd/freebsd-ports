# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	xmoto
PORTVERSION=	0.5.10
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/xmoto/xmoto/${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Challenging 2D motocross platform game

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		curl:${PORTSDIR}/ftp/curl \
		xdg-basedir:${PORTSDIR}/x11/libxdg-basedir
BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig libxml2
USE_LUA=	5.1
USE_SQLITE=	3
USE_SDL=	sdl mixer ttf net
USE_GL=		gl glu
USE_DOS2UNIX=	src/*.cpp src/*.h
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog

OPTIONS_DEFINE=	ASIAN_TTF DOCS NLS
ASIAN_TTF_DESC=	Use asian TTF font

MAN6=		xmoto.6

DESKTOP_ENTRIES="XMoto" \
		"Motorcross game" \
		"${DATADIR}/xmoto_icone_x.ico" \
		"xmoto" \
		"Game;SportsGame;ArcadeGame;" \
		false

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MASIAN_TTF}
RUN_DEPENDS+=	${LOCALBASE}/lib/X11/fonts/TrueType/bkai00mp.ttf:${PORTSDIR}/chinese/arphicttf
CONFIGURE_ARGS+=--with-asian-ttf-file=${LOCALBASE}/lib/X11/fonts/TrueType/bsmi00lp.ttf
.else
CONFIGURE_ARGS+=--without-asian-ttf-file
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
PLIST_SUB+=	NLS=""
CONFIGURE_ENV+=	LIBS="-lintl"
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
