# Created by: ada@bsd.org
# $FreeBSD$

PORTNAME=	freeciv
PORTVERSION=	2.4.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/freeciv/Freeciv%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

RUN_DEPENDS=	hicolor-icon-theme>=0:${PORTSDIR}/misc/hicolor-icon-theme
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl

USES=		gettext gmake iconv libtool pkgconfig tar:bzip2 python
USE_SQLITE=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} --program-transform-name= \
		--enable-aimodules --enable-shared \
		--enable-fcdb=sqlite3

OPTIONS_DEFINE?=	NLS X11 SDL MYSQL IPV6 DOCS
OPTIONS_DEFAULT?=	NLS X11 IPV6
OPTIONS_SUB=		yes
SDL_CONFIGURE_ON=	--enable-client=gtk,sdl
SDL_USE=		SDL=sdl,image,ttf
MYSQL_CONFIGURE_ON=	--enable-fcdb=mysql --with-mysql-prefix=${LOCALBASE}
MYSQL_USE=		MYSQL=yes
IPV6_CONFIGURE_EANBALE=	ipv6
NLS_USES=		gettext

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
USE_SDL+=	mixer
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
. if ! ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=--enable-client=gtk
. endif
CONFLICTS=	freeciv-nox11-[0-9]*
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=--enable-client=no
CONFLICTS=	freeciv-[0-9]*
PLIST_SUB+=	GTK="@comment "
.endif

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in|${XARGS} ${REINPLACE_CMD} -e \
		'/pkgdatadir/s|[(]datadir)/@PACKAGE@|(prefix)/${DATADIR_REL}|'
	${REINPLACE_CMD} 's/minor=99/minor=0/' ${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_DATA} ${WRKSRC}/data/civclient.dsc ${STAGEDIR}${DATADIR}/
	cd ${STAGEDIR}/${PREFIX}/bin && ${LN} -s freeciv-gtk2 freeciv-client
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfreeciv*.so
	-${RMDIR} ${STAGEDIR}${PREFIX}/lib/fcai

.include <bsd.port.mk>
