# New ports collection makefile for:	freeciv
# Date created:		Jun 20 1997
# Whom:			ada@bsd.org
#
# $FreeBSD$
#

PORTNAME=	freeciv
PORTVERSION=	2.2.2
CATEGORIES=	games
MASTER_SITES=	SF/freeciv/Freeciv%20${PORTVERSION:R}/${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Free turn-based multiplayer strategy

RUN_DEPENDS=	hicolor-icon-theme>=0:${PORTSDIR}/misc/hicolor-icon-theme

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
LDFLAGS=	-L${LOCALBASE}/lib
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-libiconv-prefix=${PREFIX} --program-transform-name=
INSTALLS_ICONS=	yes

MAN6=		freeciv-server.6 freeciv-client.6 \
		freeciv-xaw.6 freeciv-win32.6 freeciv-sdl.6 freeciv-gtk2.6 \
		freeciv-ftwl.6

.ifndef WITHOUT_X11
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.6:${PORTSDIR}/graphics/png \
		ggz.5:${PORTSDIR}/games/libggz \
		ggz-gtk.1:${PORTSDIR}/games/ggz-gtk-client \
		ggzcore.9:${PORTSDIR}/games/ggz-client-libs \
		ggzmod.5:${PORTSDIR}/games/ggz-client-libs
USE_XORG=	xpm
USE_SDL=	mixer
USE_GNOME=	gtk20
CONFIGURE_ARGS+=--enable-client=gtk
CONFLICTS=	freeciv-nox11-[0-9]*
PLIST_SUB+=	X11="" GTK=""
.else
PKGNAMESUFFIX?=	-nox11
CONFIGURE_ARGS+=--enable-client=no
CONFLICTS=	freeciv-[0-9]*
PLIST_SUB+=	X11="@comment " GTK="@comment "
.endif

.ifdef WITH_SDL
CONFIGURE_ARGS+=--enable-client=gtk,sdl
USE_SDL=	sdl image ttf
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.ifndef WITHOUT_MYSQL
CONFIGURE_ARGS+=--enable-auth --with-mysql-prefix=${LOCALBASE}
USE_MYSQL=	yes
.endif

.ifdef WITHOUT_IPV6
CONFIGURE_ARGS+=--disable-ipv6
.endif

.ifdef WITHOUT_NLS
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test.*==/s|==|=|;\
		/^LIBS/s|mixer|mixer $$SDL_LIBS|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in|${XARGS} ${REINPLACE_CMD} -e\
		'/pkgdatadir/s|$$[(]datadir[)]/@PACKAGE@|${DATADIR}|'

.ifndef WITHOUT_X11
post-install:
	@${INSTALL_DATA} ${WRKSRC}/data/civclient.dsc ${DATADIR}/
	@cd ${PREFIX}/bin && ${LN} -s freeciv-gtk2 freeciv-client
.endif

.include <bsd.port.mk>
