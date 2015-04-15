# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	latexila
PORTVERSION=	3.14.4
CATEGORIES=	editors
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Integrated LaTeX environment

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala \
	itstool:${PORTSDIR}/textproc/itstool \
	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee \
	libgtkspell3-3.so:${PORTSDIR}/textproc/gtkspell3

USES=	pkgconfig gmake gettext desktop-file-utils tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 gtksourceview3 intltool intlhack libxml2
USE_TEX=	latex dvipsk
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--without-help-dir

GLIB_SCHEMAS=	org.gnome.latexila.gschema.xml

.include <bsd.port.mk>
