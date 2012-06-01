# New ports collection makefile for:   gnome-globalmenu
# Date created:        27 February 2009
# Whom:                Gustavo Perez
#
# $FreeBSD$
#

PORTNAME=		gnome-globalmenu
PORTVERSION=		0.7.10
PORTREVISION=	2
CATEGORIES=		deskutils
MASTER_SITES=		http://gnome2-globalmenu.googlecode.com/files/

MAINTAINER=		gustau.perez@gmail.com
COMMENT=		Global menu for gnome

LIB_DEPENDS=		notify.4:${PORTSDIR}/devel/libnotify

USE_GNOME=		gnomepanel gnomedesktop

USE_BZIP2=		yes
USE_LDCONFIG=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_AUTOTOOLS=		libtool automake:env autoheader:env
INSTALLS_ICONS=		yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS=		XFCE4_PANEL "Xfce panel applet" Off

.include <bsd.port.options.mk>

.if defined(WITHOUT_XFCE4_PANEL)
CONFIGURE_ARGS+=	--without-xfce4-panel
PLIST_SUB+=		XFCE4_PANEL="@comment "
.else
LIB_DEPENDS+=		libxfce4panel-1.0:${PORTSDIR}/x11-wm/xfce4-panel
CONFIGURE_ARGS+=	--with-xfce4-panel
PLIST_SUB+=		XFCE4_PANEL=""
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
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
