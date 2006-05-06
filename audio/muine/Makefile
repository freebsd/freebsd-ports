# New ports collection makefile for:	muine
# Date created:				20040615
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.45 2006/02/15 17:16:54 tmclau02 Exp $
#

PORTNAME=	muine
PORTVERSION=	0.8.4
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine-player.org/releases/

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Mono based Gnome audio player

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm \
		vorbis.3:${PORTSDIR}/audio/libvorbis \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

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
CONFIGURE_ARGS+=	--enable-xine=yes
LIB_DEPENDS+=	xine.15:${PORTSDIR}/multimedia/libxine
.else
USE_GSTREAMER80+=	gconf
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/dbus-1.0|(prefix)/share/dbus-1|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|libmusicbrainz.so.4|libmusicbrainz.so|g' \
		${WRKSRC}/src/muine.exe.config.in

post-install:
	${MKDIR} ${PREFIX}/lib/muine/plugins
.for _plugin in TrayIcon.dll DashboardPlugin.dll
	${INSTALL_DATA} ${WRKSRC}/plugins/${_plugin} ${PREFIX}/lib/muine/plugins
.endfor

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
