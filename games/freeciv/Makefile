# Created by: ada@bsd.org
# $FreeBSD$

PORTNAME=	freeciv
PORTVERSION=	2.5.6
CATEGORIES=	games
MASTER_SITES=	SF/freeciv/Freeciv%20${PORTVERSION:R}/${PORTVERSION} \
		http://download.gna.org/freeciv/stable/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

LICENSE=	GPLv2+

RUN_DEPENDS=	hicolor-icon-theme>=0:misc/hicolor-icon-theme
LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libcurl.so:ftp/curl

USES=		gmake iconv libtool localbase pkgconfig tar:bzip2 python \
		sqlite readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	${ICONV_CONFIGURE_ARG} --program-transform-name= \
		--enable-aimodules --enable-shared \
		--enable-fcdb=sqlite3

PORTDATA=	*

OPTIONS_DEFINE?=	NLS X11 SDL MYSQL IPV6 DOCS
OPTIONS_DEFAULT?=	NLS X11 IPV6
OPTIONS_SUB=		yes
SDL_CONFIGURE_ON=	--enable-client=gtk,sdl
SDL_USE=		SDL=sdl,image,ttf,gfx
MYSQL_CONFIGURE_ON=	--enable-fcdb=mysql --with-mysql-prefix=${LOCALBASE}
MYSQL_USES=		mysql
IPV6_CONFIGURE_EANBALE=	ipv6
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL} && empty(PORT_OPTIONS:MX11)
IGNORE=		cannot use SDL without X11: re-run make config
.endif

.if ${PORT_OPTIONS:MX11}
LIB_DEPENDS+=	libtiff.so:graphics/tiff \
		libpng.so:graphics/png \
		libggz.so:games/libggz \
		libggz-gtk.so:games/ggz-gtk-client \
		libggzcore.so:games/ggz-client-libs \
		libggzmod.so:games/ggz-client-libs
USE_XORG=	xpm
USE_SDL+=	mixer
USE_GNOME=	gtk20 cairo
INSTALLS_ICONS=	yes
. if ! ${PORT_OPTIONS:MSDL}
CONFIGURE_ARGS+=--enable-client=gtk
. endif
CONFLICTS=	freeciv-nox11-[0-9]*
PLIST_SUB+=	GTK=""
.else
CONFIGURE_ARGS+=--enable-client=no --enable-fcmp=no
CONFLICTS=	freeciv-[0-9]*
PLIST_SUB+=	GTK="@comment "
.endif

post-patch:
	${FIND} ${WRKSRC} -name Makefile.in|${XARGS} ${REINPLACE_CMD} -e \
		'/pkgdatadir/s|[(]datadir)/@PACKAGE@|(prefix)/${DATADIR_REL}|'
	${REINPLACE_CMD} 's/minor=99/minor=0/' ${WRKSRC}/configure
	${REINPLACE_CMD} 's/(LIB_GGZMOD)/& $$(LIB_GGZ_GTK)/' \
		${WRKSRC}/client/Makefile.in

post-install:
.if ${PORT_OPTIONS:MX11}
	${INSTALL_DATA} ${WRKSRC}/data/civclient.dsc ${STAGEDIR}${DATADIR}/
	cd ${STAGEDIR}/${PREFIX}/bin && ${LN} -s freeciv-gtk2 freeciv-client
.endif
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfreeciv*.so
	${RM} ${STAGEDIR}${PREFIX}/etc/ggz.modules

.include <bsd.port.mk>
