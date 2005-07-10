# New ports collection makefile for:	muine
# Date created:				20040615
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
# $Id: Makefile,v 1.26 2005/06/30 01:05:54 tmclau02 Exp $

PORTNAME=	muine
PORTVERSION=	0.8.3
PORTREVISION=	3
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono based Gnome audio player

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm \
		vorbis.3:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp-devel \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp-devel \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui
USE_X_PREFIX=   yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GACUTIL_FLAGS="/package muine /gacdir $(DESTDIR)$(libdir) /root $(DESTDIR)$(libdir)"

GCONF_SCHEMAS=	muine.schemas

OPTIONS=	XINE "Enable Xine backend" off \
		FAAD "Enable faad support" off

.include <bsd.port.pre.mk>
.if defined (WITH_FAAD)
LIB_DEPENDS+=	faad.0:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=	--disable-faad2
.endif

.if defined (WITH_XINE)
CONFIGURE_ARGS+= --enable-xine=yes
LIB_DEPENDS+=	xine.13:${PORTSDIR}/multimedia/libxine
.else
USE_GSTREAMER+=	gconf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/dbus-1.0|(prefix)/share/dbus-1|g' \
		${WRKSRC}/data/Makefile.in

post-install:
	${MKDIR} ${PREFIX}/lib/muine/plugins
.for _plugin in TrayIcon.dll DashboardPlugin.dll
	${INSTALL_DATA} ${WRKSRC}/plugins/${_plugin} ${PREFIX}/lib/muine/plugins
.endfor

.include <bsd.port.post.mk>
