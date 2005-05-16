# New ports collection makefile for:	muine
# Date created:				20040615
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
# $Id: Makefile,v 1.17 2005/05/12 21:44:41 tmclau02 Exp $

PORTNAME=	muine
PORTVERSION=	0.8.3
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono based Gnome audio player

LIB_DEPENDS=	FLAC.7:${PORTSDIR}/audio/flac \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm
BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp-devel \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui
USE_X_PREFIX=   yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GACUTIL_FLAGS="/package muine /gacdir $(DESTDIR)$(libdir) /root $(DESTDIR)$(libdir)"

GCONF_SCHEMAS=	muine.schemas

OPTIONS=	XINE "Enable Xine backend" off

.include <bsd.port.pre.mk>

.if defined (WITH_XINE)
CONFIGURE_ARGS+= --enable-xine=yes
LIB_DEPENDS+=	xine.12:${PORTSDIR}/multimedia/libxine
.else
USE_GNOME+=	gstreamerplugins
.endif

.include <bsd.port.post.mk>
