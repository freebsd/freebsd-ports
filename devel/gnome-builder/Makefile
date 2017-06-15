# $FreeBSD$

PORTNAME=	gnome-builder
PORTVERSION=	3.16.2
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	rm@FreeBSD.org
COMMENT=	IDE for writing software for GNOME

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	intltool-update:textproc/intltool \
		llvm-config35:devel/llvm35 \
		clang35:lang/clang35
LIB_DEPENDS=	libgit2-glib-1.0.so:devel/libgit2-glib \
		libpeas-1.0.so:devel/libpeas \
		libdevhelp-3.so:devel/devhelp \
		libgjs.so:lang/gjs \
		libpcre.so:devel/pcre

PORTSCOUT=	limitw:1,even
PORTDOCS=	*

USES=		cpe gettext gmake libtool pathfix pkgconfig tar:xz
USE_GNOME=	glib20 gtk30 gtksourceview3 gtk-update-icon-cache py3gobject3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-debug
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
CPE_VENDOR=	gnome

GLIB_SCHEMAS=	org.gnome.builder.editor.gschema.xml \
		org.gnome.builder.editor.language.gschema.xml \
		org.gnome.builder.experimental.gschema.xml \
		org.gnome.builder.project-tree.gschema.xml

.include <bsd.port.mk>
