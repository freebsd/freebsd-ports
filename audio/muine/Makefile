# New ports collection makefile for:	muine
# Date created:				20040615
# Whom:					Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#

PORTNAME=	muine
PORTVERSION=	0.6.3
CATEGORIES=	audio gnome
MASTER_SITES=	http://muine.gooeylinux.org/

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Mono based Gnome audio player

LIB_DEPENDS=	xine.9:${PORTSDIR}/multimedia/libxine \
		FLAC.5:${PORTSDIR}/audio/flac \
		id3tag.2:${PORTSDIR}/audio/libid3tag \
		gdbm:${PORTSDIR}/databases/gdbm
BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-sharp.pc:${PORTSDIR}/x11-toolkits/gtk-sharp
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/gtk-sharp.pc:${PORTSDIR}/x11-toolkits/gtk-sharp

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack intltool libgnomeui
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GLIB_MIVER=	400

post-patch:
	@${REINPLACE_CMD} -e 's|%%GLIB_MIVER%%|${GLIB_MIVER}|g' \
		${WRKSRC}/src/muine.exe.config.in

.include <bsd.port.mk>
