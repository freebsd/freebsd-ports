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

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libcurl.so:${PORTSDIR}/ftp/curl \
		libxdg-basedir.so:${PORTSDIR}/x11/libxdg-basedir
BUILD_DEPENDS=	${LOCALBASE}/lib/libode.a:${PORTSDIR}/devel/ode

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake
USE_GNOME=	libxml2
USE_LUA=	5.1
USE_SQLITE=	3
USE_SDL=	sdl mixer ttf net
USE_GL=		gl glu
USE_DOS2UNIX=	src/*.cpp src/*.h

CPPFLAGS+=	-I${LOCALBASE}/include -I${LUA_INCDIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${LUA_LIBDIR}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PORTDOCS=	README ChangeLog
PORTDATA=	*

OPTIONS_DEFINE=	ASIAN_TTF DOCS NLS
ASIAN_TTF_DESC=	Use asian TTF font

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
USES+=		gettext
PLIST_SUB+=	NLS=""
CONFIGURE_ENV+=	LIBS="-lintl"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
