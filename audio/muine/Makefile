# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$
#   $Id: Makefile,v 1.54 2007/01/26 03:17:25 tmclau02 Exp $

PORTNAME=	muine
PORTVERSION=	0.8.11
PORTREVISION=	12
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Mono based Gnome audio player

BROKEN=		Fails to run

LIB_DEPENDS=	FLAC:${PORTSDIR}/audio/flac \
		id3tag.0:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm \
		vorbis.4:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:${PORTSDIR}/audio/taglib-sharp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GMAKE=	yes
USES=		gettext shebangfix
USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui gnomesharp20
USE_GSTREAMER=	gconf
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
SHEBANG_FILES=	src/muine.in
bash_CMD=	${SETENV} bash

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

GCONF_SCHEMAS=	muine.schemas

.include <bsd.port.mk>
