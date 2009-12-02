# New ports collection makefile for:	muine
# Date created:				20040615
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.54 2007/01/26 03:17:25 tmclau02 Exp $
#

PORTNAME=	muine
PORTVERSION=	0.8.11
PORTREVISION=	1
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME

MAINTAINER=	mono@FreeBSD.org
COMMENT=	Mono based Gnome audio player

LIB_DEPENDS=	FLAC.10:${PORTSDIR}/audio/flac \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm \
		vorbis.4:${PORTSDIR}/audio/libvorbis \
		musicbrainz.4:${PORTSDIR}/audio/libmusicbrainz
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:${PORTSDIR}/audio/taglib-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui gnomesharp20
USE_GSTREAMER=	gconf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	muine.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|libmusicbrainz.so.4|libmusicbrainz.so|g' \
		${WRKSRC}/src/muine.exe.config.in
	@${REINPLACE_CMD} -e 's|/bin/bash|/usr/bin/env bash|g' \
		${WRKSRC}/src/muine.in

.include <bsd.port.mk>
