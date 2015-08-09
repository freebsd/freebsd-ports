# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	latexila
PORTVERSION=	3.16.1
CATEGORIES=	editors
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	olivierd@FreeBSD.org
COMMENT=	Integrated LaTeX environment

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala \
	itstool:${PORTSDIR}/textproc/itstool \
	${LOCALBASE}/libdata/pkgconfig/gsettings-desktop-schemas.pc:${PORTSDIR}/devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgee-0.8.so:${PORTSDIR}/devel/libgee \
	libgtkspell3-3.so:${PORTSDIR}/textproc/gtkspell3

USES=	desktop-file-utils gettext-tools gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	glib20 gtk30 gtksourceview3 intltool intlhack libxml2
USE_TEX=	latex dvipsk
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=--without-help-dir

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

GLIB_SCHEMAS=	org.gnome.latexila.gschema.xml

.include <bsd.port.mk>
