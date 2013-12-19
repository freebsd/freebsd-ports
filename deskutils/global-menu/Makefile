# Created by: Gustavo Perez
# $FreeBSD$

PORTNAME=		gnome-globalmenu
PORTVERSION=		0.7.10
PORTREVISION=	3
CATEGORIES=		deskutils
MASTER_SITES=		http://gnome2-globalmenu.googlecode.com/files/

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Global menu for gnome

LIB_DEPENDS=		libnotify.so:${PORTSDIR}/devel/libnotify

USE_GNOME=		gnomepanel gnomedesktop

USE_BZIP2=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USES=			gmake pkgconfig
USE_AUTOTOOLS=		libtool automake:env autoheader:env
INSTALLS_ICONS=		yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		XFCE4_PANEL NLS
XFCE4_PANEL_DESC=	Xfce panel applet

NO_STAGE=	yes
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

MAN1=			gnome-globalmenu.1

GCONF_SCHEMAS=		gnome-globalmenu.schemas

post-install:
		@${INSTALL_DATA} ${WRKSRC}/applet/GlobalMenu_PanelApplet.server \
			${LOCALBASE}/libdata/bonobo/servers
		@${CAT} ${PKGMESSAGE}

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Leaves files behind on deinstall on sparc64
.endif

.include <bsd.port.post.mk>
