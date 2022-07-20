PORTNAME=	gnome-latex
PORTVERSION=	3.40.0
CATEGORIES=	editors
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated LaTeX environment

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:lang/vala \
		itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libfribidi.so:converters/fribidi \
		libenchant-2.so:textproc/enchant2 \
		libtepl-6.so:x11-toolkits/tepl6 \
		libgspell-1.so:textproc/gspell

USES=		compiler:c11 desktop-file-utils gettext gmake gnome \
		pkgconfig tar:xz
GNU_CONFIGURE=	yes
USE_GNOME=	cairo dconf intltool gtksourceview4
USE_TEX=	latex dvipsk
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

GLIB_SCHEMAS=	org.gnome.gnome-latex.gschema.xml

.include <bsd.port.mk>
