# New ports collection makefile for:	gdcd
# Date created:				Sat 3 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	gdcd
PORTVERSION=	0.2.1
CATEGORIES=	audio
MASTER_SITES=	http://cdcd.undergrid.net/gdcd/source_archive/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	cdaudio.1:${PORTSDIR}/audio/libcdaudio \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=	${X11BASE}/bin/gtk12-config

USE_X_PREFIX=	yes
USE_AUTOMAKE=	yes
AUTOMAKE=	automake -a -i
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GLIB_CONFIG="${GTK_CONFIG}" \
		GTK_CONFIG="${GTK_CONFIG}" \
		LIBS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-glibtest --disable-gtktest

pre-configure:
	@cd ${WRKSRC}; aclocal -I ${X11BASE}/share/aclocal

.include <bsd.port.mk>
