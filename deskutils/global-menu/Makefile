# Created by: Gustavo Perez
# $FreeBSD$

PORTNAME=	gnome-globalmenu
PORTVERSION=	0.7.10
PORTREVISION=	4
CATEGORIES=	deskutils
MASTER_SITES=	http://gnome2-globalmenu.googlecode.com/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Global menu for gnome

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify

USE_GNOME=	gnomepanel gnomedesktop

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USES=		gmake libtool pkgconfig tar:bzip2
USE_AUTOTOOLS=	automake:env autoheader:env
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	gnome-globalmenu.schemas

OPTIONS_DEFINE=		XFCE4_PANEL NLS
XFCE4_PANEL_DESC=	Xfce panel applet

BROKEN_sparc64=	Leaves files behind on deinstall on sparc64

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXFCE4_PANEL}
USE_XFCE=	panel
CONFIGURE_ARGS+=	--with-xfce4-panel
PLIST_SUB+=		XFCE4_PANEL=""
.else
CONFIGURE_ARGS+=	--without-xfce4-panel
PLIST_SUB+=		XFCE4_PANEL="@comment "
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.endif

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libdata/bonobo/servers
	${INSTALL_DATA} ${WRKSRC}/applet/GlobalMenu_PanelApplet.server \
		${STAGEDIR}${PREFIX}/libdata/bonobo/servers

.include <bsd.port.mk>
