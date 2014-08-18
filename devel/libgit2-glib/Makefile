# Created by: Gustau Perez <gustau.perez@gmail.com>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libgit2-glib/Makefile 19812 2014-08-14 17:06:28Z gusi $

PORTNAME=	libgit2-glib
PORTVERSION=	0.0.20
CATEGORIES=	devel gnome
MASTER_SITES=	https://git.gnome.org/browse/libgit2-glib/snapshot/
DIST_SUBDIR=	gnome3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Glib wrapper library around the libgit2 git access library

BUILD_DEPENDS=	gnome-autogen.sh:${PORTSDIR}/devel/gnome-common \
		gtkdoc-check:${PORTSDIR}/textproc/gtk-doc
LIB_DEPENDS=	libgit2.so:${PORTSDIR}/devel/libgit2

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	glib20 gnomeprefix gtk30 intlhack introspection
USE_AUTOTOOLS=	automake libtoolize
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	--disable-python
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

pre-configure:
	cd ${WRKSRC} && NOCONFIGURE=yes ${SH} ./autogen.sh

.include <bsd.port.mk>
