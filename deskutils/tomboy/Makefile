# New ports collection makefile for:		tomboy
# Date created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	tomboy
PORTVERSION=	1.12.2
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Personal note taking system for the GNOME desktop

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
BUILD_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp-2.4/gmime-sharp.dll:${PORTSDIR}/mail/gmime24-sharp \
		${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:${PORTSDIR}/devel/dbus-sharp-glib \
		mautil:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp-2.4/gmime-sharp.dll:${PORTSDIR}/mail/gmime24-sharp \
		${LOCALBASE}/libdata/pkgconfig/dbus-sharp-glib-1.0.pc:${PORTSDIR}/devel/dbus-sharp-glib \
		mautil:${PORTSDIR}/devel/mono-addins

USE_XZ=		yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack intlhack gnomeprefix gnomedesktopsharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--enable-evolution=yes

MAN1=		tomboy.1
GCONF_SCHEMAS=	tomboy.schemas

OPTIONS=	APPLET "Enable GNOME panel applet" off

# Restrict to stable (even) versions, indicated by the second component.
PORTSCOUT=	limitw:1,even

.include <bsd.port.pre.mk>

.if defined(WITH_APPLET)
CONFIGURE_ARGS+=--enable-panel-applet
PLIST_SUB+=	APPLET=""
.else
CONFIGURE_ARGS+=--disable-panel-applet
PLIST_SUB+=	APPLET="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|`$$PKG_CONFIG --variable=libdir libpanelapplet-2.0`|"$$libdir"|g; \
	s|PANELAPPLET_SERVER_DIR="$$libdir|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g; \
	s|PANELAPPLET_SERVER_DIR="$$PANELAPPLET_LIBDIR|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/Tomboy/tomboy*.in
	@${REINPLACE_CMD} 's|gmime-sharp|gmime-sharp-2.4|g' \
		${WRKSRC}/configure

.include "${PORTSDIR}/lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
