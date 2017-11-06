# Created by: Olivier Duchateau
# $FreeBSD$

PORTNAME=	latexila
PORTVERSION=	3.22.1
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Integrated LaTeX environment

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libgspell-1.so:textproc/gspell

USES=		compiler:c11 desktop-file-utils gettext-tools gmake pkgconfig \
		tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	cairo glib20 gtk30 gtksourceview3 intltool intlhack libxml2
USE_TEX=	latex dvipsk
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

GLIB_SCHEMAS=	org.gnome.latexila.gschema.xml

.include <bsd.port.mk>
