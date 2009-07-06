# New ports collection makefile for:	muine
# Date created:				20040615
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.54 2007/01/26 03:17:25 tmclau02 Exp $
#

PORTNAME=	muine
PORTVERSION=	0.8.10
PORTREVISION=	2
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono based Gnome audio player

BROKEN=		doesn't build and is apparently unmaintained

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui gnomesharp20
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GACUTIL_FLAGS="/package muine /gacdir $(libdir) /root $(libdir)"

CONFIGURE_ARGS+=	--enable-compile-warnings=maximum

GCONF_SCHEMAS=	muine.schemas

OPTIONS=	XINE "Enable Xine backend" off \
		FAAD "Enable faad support" off

.include <bsd.port.pre.mk>
.if defined (WITH_FAAD)
LIB_DEPENDS+=	faad.2:${PORTSDIR}/audio/faad
.else
CONFIGURE_ARGS+=	--disable-faad2
.endif

.if defined (WITH_XINE)
CONFIGURE_ARGS+=	--enable-xine=yes
LIB_DEPENDS+=	xine.1:${PORTSDIR}/multimedia/libxine
.else
USE_GSTREAMER+=	gconf
CONFIGURE_ARGS+=	--enable-gstreamer=0.10
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|(libdir)/dbus-1.0|(prefix)/share/dbus-1|g' \
		${WRKSRC}/data/Makefile.in
	@${REINPLACE_CMD} -e 's|libmusicbrainz.so.4|libmusicbrainz.so|g' \
		${WRKSRC}/src/muine.exe.config.in
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|g' \
		${WRKSRC}/src/muine.in

post-install:
	${MKDIR} ${PREFIX}/lib/muine/plugins
.for _plugin in TrayIcon.dll
	${INSTALL_DATA} ${WRKSRC}/plugins/${_plugin} ${PREFIX}/lib/muine/plugins
.endfor

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
