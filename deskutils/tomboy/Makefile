# New ports collection makefile for:		tomboy
# Date created:					20041011
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.22 2006/02/16 02:44:45 tmclau02 Exp $
#

PORTNAME=	tomboy
PORTVERSION=	0.3.5
PORTREVISION=	4
CATEGORIES=	deskutils gnome
MASTER_SITES=	http://www.beatniksoftware.com/tomboy/releases/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Personal note taking system for the GNOME desktop

LIB_DEPENDS=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp

USE_GNOME=	gnomehack gnometarget intltool gnomeprefix gnomepanel
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		tomboy.1
GCONF_SCHEMAS=	tomboy.schemas

.include <bsd.port.pre.mk>

# Tomboy's Evolution plugin relies on gmime# and not evo# according to
# configure.  Enable if either evo or gmime# is installed.
.if defined (WITH_EVOLUTION) || exists (${X11BASE}/bin/evolution) || exists (${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll)
CONFIGURE_ARGS+= --enable-evolution=yes
BUILD_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll:${PORTSDIR}/mail/gmime2-sharp
RUN_DEPENDS=	${LOCALBASE}/lib/mono/gmime-sharp/gmime-sharp.dll:${PORTSDIR}/mail/gmime2-sharp
PLIST_SUB+=	EVO:=""
.else
PLIST_SUB+=	EVO:="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/dbus-1.0|(prefix)/share/dbus-1|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|`$$PKG_CONFIG --variable=libdir libpanelapplet-2.0`|"$$libdir"|g; \
	s|PANELAPPLET_SERVER_DIR="$$libdir|PANELAPPLET_SERVER_DIR="$$prefix/libdata|g' \
		${WRKSRC}/configure

post-install:
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE} ${WRKSRC}/Tomboy/Plugins/FixedWidth.dll ${PREFIX}/lib/tomboy/Plugins
	${INSTALL} ${COPY} ${_BINOWNGRP} -m ${BINMODE} ${WRKSRC}/Tomboy/Plugins/NoteOfTheDay.dll ${PREFIX}/lib/tomboy/Plugins

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
