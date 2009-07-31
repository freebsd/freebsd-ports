# New ports collection makefile for:		tomboy
# Date created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.49 2007/09/20 15:16:43 killfill Exp $
#

PORTNAME=	tomboy
PORTVERSION=	0.14.3
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome2

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Personal note taking system for the GNOME desktop

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
BUILD_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp-2.4/gmime-sharp.dll:${PORTSDIR}/mail/gmime24-sharp \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		mautil:${PORTSDIR}/devel/mono-addins
RUN_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp-2.4/gmime-sharp.dll:${PORTSDIR}/mail/gmime24-sharp \
		${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		mautil:${PORTSDIR}/devel/mono-addins

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget intlhack gnomeprefix gnomedesktopsharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--enable-evolution=yes \
		--enable-dbus=yes \
		--enable-dbus-service-dir-check=no \
		--with-dbus-service-dir=${PREFIX}/share/dbus-1/services
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		DBUS_SERVICE_DIR="${PREFIX}/share/dbus-1/services"

MAN1=		tomboy.1
GCONF_SCHEMAS=	tomboy.schemas

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's|`$$PKG_CONFIG --variable=libdir libpanelapplet-2.0`|"$$libdir"|g; \
	s|PANELAPPLET_SERVER_DIR="$$libdir|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g; \
	s|PANELAPPLET_SERVER_DIR="$$PANELAPPLET_LIBDIR|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} 's|/bin/bash|/bin/sh|g' \
		${WRKSRC}/Tomboy/tomboy*.in
	@${REINPLACE_CMD} 's|gmime-sharp|gmime-sharp-2.4|g' \
		${WRKSRC}/configure

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
