# New ports collection makefile for:		tomboy
# Date created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.25 2006/09/15 02:47:48 tmclau02 Exp $
#

PORTNAME=	tomboy
PORTVERSION=	0.4.1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Personal note taking system for the GNOME desktop

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell \
    		dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib
BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20
RUN_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget intltool gnomeprefix gnomepanel
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		tomboy.1
GCONF_SCHEMAS=	tomboy.schemas

.include <bsd.port.pre.mk>

# Tomboy's Evolution plugin relies on gmime# and not evo# according to
# configure.  Enable if either evo or gmime# is installed.
.if defined (WITH_EVOLUTION) || exists (${LOCALBASE}/bin/evolution) || exists (${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll)
CONFIGURE_ARGS+= --enable-evolution=yes
BUILD_DEPENDS+=	${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll:${PORTSDIR}/mail/gmime2-sharp
RUN_DEPENDS+=	${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll:${PORTSDIR}/mail/gmime2-sharp
PLIST_SUB+=	EVO:=""
.else
PLIST_SUB+=	EVO:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/dbus-1.0|(prefix)/share/dbus-1|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|`$$PKG_CONFIG --variable=libdir libpanelapplet-2.0`|"$$libdir"|g; \
	s|PANELAPPLET_SERVER_DIR="$$libdir|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g; \
	s|PANELAPPLET_SERVER_DIR="$$PANELAPPLET_LIBDIR|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE} ${WRKSRC}/Tomboy/Plugins/FixedWidth.dll ${PREFIX}/lib/tomboy/Plugins
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE} ${WRKSRC}/Tomboy/Plugins/NoteOfTheDay.dll ${PREFIX}/lib/tomboy/Plugins

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
