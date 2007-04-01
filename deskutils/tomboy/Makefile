# New ports collection makefile for:		tomboy
# Date created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.42 2007/03/13 00:44:36 killfill Exp $
#

PORTNAME=	tomboy
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Personal note taking system for the GNOME desktop

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
BUILD_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll:${PORTSDIR}/mail/gmime2-sharp
RUN_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll:${PORTSDIR}/mail/gmime2-sharp \
		dbus-daemon:${PORTSDIR}/devel/dbus

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnometarget intltool gnomeprefix gnomesharp20
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

CONFIGURE_ARGS+=--enable-evolution=yes \
		--enable-dbus=yes \
		--enable-dbus-service-dir-check=no
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

post-install:
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE} ${WRKSRC}/Tomboy/Plugins/FixedWidth.dll ${PREFIX}/lib/tomboy/Plugins
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE} ${WRKSRC}/Tomboy/Plugins/NoteOfTheDay.dll ${PREFIX}/lib/tomboy/Plugins

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
