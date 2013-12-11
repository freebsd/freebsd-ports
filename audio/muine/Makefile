# Created by: Tom McLaughlin <tmclaugh@sdf.lonestar.org>
# $FreeBSD$

PORTNAME=	muine
PORTVERSION=	0.8.11
PORTREVISION=	12
CATEGORIES=	audio gnome
MASTER_SITES=	GNOME

MAINTAINER=	cy@FreeBSD.org
COMMENT=	Mono based Gnome audio player

IGNORE=		Fails to run

LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libgdbm.so:${PORTSDIR}/databases/gdbm \
		libvorbis.so:${PORTSDIR}/audio/libvorbis
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/ndesk-dbus-glib-1.0.pc:${PORTSDIR}/devel/ndesk-dbus-glib \
		${LOCALBASE}/libdata/pkgconfig/taglib-sharp.pc:${PORTSDIR}/audio/taglib-sharp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext gmake pathfix shebangfix
NO_STAGE=	yes
USE_GNOME=	gnomeprefix intltool libgnomeui gnomesharp20
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
