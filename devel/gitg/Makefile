# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	gitg
PORTVERSION=	3.18.0
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GTK-based git repository viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjson-glib-1.0.so:${PORTSDIR}/devel/json-glib \
		libgee-0.8.so:${PORTSDIR}/devel/libgee \
		libgit2-glib-1.0.so:${PORTSDIR}/devel/libgit2-glib \
		libpeas-1.0.so:${PORTSDIR}/devel/libpeas \
		libgtkspell3-3.so:${PORTSDIR}/textproc/gtkspell3 \
		libwebkit2gtk-3.0.so:${PORTSDIR}/www/webkit-gtk3
BUILD_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas \
		valac:${PORTSDIR}/lang/vala
RUN_DEPENDS=	gsettings-desktop-schemas>=0:${PORTSDIR}/devel/gsettings-desktop-schemas

CONFLICTS=	gitg0-[0-9]*

USES=		compiler:c11 desktop-file-utils gmake libtool pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-maintainer-mode \
		--enable-compile-warnings=no
USE_GNOME=	glib20 gtk30 gtksourceview3 intlhack introspection
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.gnome.gitg.gschema.xml

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DEBUG NLS PYTHON
OPTIONS_SUB=	yes
DEBUG_CONFIGURE_ENABLE=	debug
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
PYTHON_USES=	python:3
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_PLIST_SUB=	PYTHON_SUFFIX=${PYTHON_SUFFIX}

.include <bsd.port.mk>
