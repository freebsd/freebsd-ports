# Created by: kipz <somicide@gmail.com>
# $FreeBSD$

PORTNAME=	gitg
PORTVERSION=	3.24.0
PORTREVISION=	1
CATEGORIES=	devel deskutils gnome
MASTER_SITES=	GNOME

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	GTK-based git repository viewer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		fails to configure

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		valac:lang/vala
LIB_DEPENDS=	libsoup-2.4.so:devel/libsoup \
		libenchant.so:textproc/enchant \
		libgee-0.8.so:devel/libgee \
		libgit2.so:devel/libgit2 \
		libgit2-glib-1.0.so:devel/libgit2-glib \
		libpeas-1.0.so:devel/libpeas \
		libgtkspell3-3.so:textproc/gtkspell3 \
		libsecret-1.so:security/libsecret
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas

CONFLICTS=	gitg0-[0-9]*
PORTSCOUT=	limitw:1,even

USES=		compiler:c11 desktop-file-utils gmake libtool localbase \
		pathfix pkgconfig tar:xz
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-silent-rules \
		--disable-maintainer-mode \
		--enable-compile-warnings=no
USE_GNOME=	cairo gtk30 gtksourceview3 intltool introspection
INSTALL_TARGET=	install-strip

INSTALLS_ICONS=	yes
GLIB_SCHEMAS=	org.gnome.gitg.gschema.xml

OPTIONS_DEFINE=	DEBUG NLS PYTHON
OPTIONS_SUB=	yes
DEBUG_CONFIGURE_ENABLE=	debug
NLS_USES=	gettext
NLS_USES_OFF=	gettext-tools
NLS_CONFIGURE_ENABLE=	nls
PYTHON_USES=	python:3.2+
PYTHON_CONFIGURE_ENABLE=	python
PYTHON_USE=	GNOME=pygobject3

.include <bsd.port.mk>
