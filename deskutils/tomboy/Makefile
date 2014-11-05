# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	tomboy
PORTVERSION=	1.14.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Personal note taking system for the GNOME desktop

BROKEN=		Uses unknown GNOME component gnomedesktopsharp20

LIB_DEPENDS=	libgtkspell.so:${PORTSDIR}/textproc/gtkspell
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:${PORTSDIR}/devel/dbus-sharp-glib \
		mautil:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:${PORTSDIR}/devel/dbus-sharp-glib \
		mautil:${PORTSDIR}/devel/mono-addins

USES=		gettext gmake libtool mono pathfix pkgconfig tar:xz
USE_GNOME=	intlhack gnomeprefix gnomedesktopsharp20
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes
GCONF_SCHEMAS=	tomboy.schemas

MAKE_JOBS_UNSAFE=yes

OPTIONS_DEFINE=	APPLET EVOLUTION
APPLET_DESC=	Enable GNOME panel applet
EVOLUTION_DESC=	Build evolution addin

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MAPPLET}
CONFIGURE_ARGS+=--enable-panel-applet
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-panel-applet
PLIST_SUB+=	APPLET="@comment "
.endif

.if ${PORT_OPTIONS:MEVOLUTION}
CONFIGURE_ARGS+=--enable-evolution
BUILD_DEPENDS+=	${LOCALBASE}/lib/mono/gmime-sharp-2.6/gmime-sharp.dll:${PORTSDIR}/mail/gmime26-sharp
RUN_DEPENDS+=	${LOCALBASE}/lib/mono/gmime-sharp-2.6/gmime-sharp.dll:${PORTSDIR}/mail/gmime26-sharp
PLIST_SUB+=	EVOLUTION=""
.else
CONFIGURE_ARGS+=--disable-evolution
PLIST_SUB+=	EVOLUTION="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|`$$PKG_CONFIG --variable=libdir libpanelapplet-2.0`|"$$libdir"|g; \
	s|PANELAPPLET_SERVER_DIR="$$libdir|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g; \
	s|PANELAPPLET_SERVER_DIR="$$PANELAPPLET_LIBDIR|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/Tomboy/tomboy*.in

.include <bsd.port.post.mk>
