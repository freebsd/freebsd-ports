# New ports collection makefile for:	muine
# Date created:				20040615
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	muine
PORTVERSION=	0.6.3
PORTREVISION=	5
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono based Gnome audio player

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm
BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui
WANT_GSTREAMER=	yes
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	muine.schemas

OPTIONS=	GSTREAMER "Enable Gstreamer backend" off

.include <bsd.port.pre.mk>

.if defined (WITH_GSTREAMER)
IGNORE=		Doesn't run with recent gstreamer.
CONFIGURE_ARGS+=--enable-gstreamer=yes
USE_GSTREAMER+=	mad vorbis flac gconf
.else
LIB_DEPENDS+=	xine.12:${PORTSDIR}/multimedia/libxine
.endif

.include <bsd.port.post.mk>
