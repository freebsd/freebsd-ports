# Created by: ada@bsd.org
# $FreeBSD$

PORTNAME=	freeciv
PORTVERSION=	2.4.1
CATEGORIES=	games
MASTER_SITES=	SF/freeciv/Freeciv%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

RUN_DEPENDS=	hicolor-icon-theme>=0:${PORTSDIR}/misc/hicolor-icon-theme
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		gettext gmake iconv pkgconfig
USE_SQLITE=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} --program-transform-name= \
		--enable-aimodules --enable-shared \
		--enable-fcdb=sqlite3

OPTIONS_DEFINE?=	X11 SDL MYSQL IPV6
OPTIONS_DEFAULT?=	X11 IPV6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL} && empty(PORT_OPTIONS:MX11)
IGNORE=		cannot use SDL without X11: re-run make config
.endif

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	libtiff.so:${PORTSDIR}/graphics/tiff \
		libpng15.so:${PORTSDIR}/graphics/png \
		libggz.so:${PORTSDIR}/games/libggz \
		libggz-gtk.so:${PORTSDIR}/games/ggz-gtk-client \
		libggzcore.so:${PORTSDIR}/games/ggz-client-libs \
		libggzmod.so:${PORTSDIR}/games/ggz-client-libs
USE_XORG=	xpm
USE_SDL=	mixer
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
CONFIGURE_ARGS+=--enable-client=gtk
CONFLICTS=	freeciv-nox11-[0-9]*
PLIST_SUB+=	X11="" GTK=""
.else
CONFIGURE_ARGS+=--enable-client=no
CONFLICTS=	freeciv-[0-9]*
PLIST_SUB+=	X11="@comment " GTK="@comment "
.endif

.if ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=--enable-client=gtk,sdl
USE_SDL=	sdl image ttf
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MMYSQL}
CONFIGURE_ARGS+=--enable-fcdb=mysql --with-mysql-prefix=${LOCALBASE}
USE_MYSQL=	yes
.endif

.if empty(PORT_OPTIONS:MIPV6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in|${XARGS} ${REINPLACE_CMD} -e \
		'/pkgdatadir/s|[(]datadir)/@PACKAGE@|(prefix)/${DATADIR_REL}|'

.if ${PORT_OPTIONS:MX11}
post-install:
	@${INSTALL_DATA} ${WRKSRC}/data/civclient.dsc ${STAGEDIR}/${DATADIR}/
	@cd ${STAGEDIR}/${PREFIX}/bin && ${LN} -s freeciv-gtk2 freeciv-client
.endif

.include <bsd.port.mk>
