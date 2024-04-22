PORTNAME=	gnome-latex
PORTVERSION=	3.44.0
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated LaTeX environment
WWW=		https://wiki.gnome.org/Apps/LaTeXila

LICENSE=	GPLv3

BUILD_DEPENDS=	itstool:textproc/itstool \
		gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas
LIB_DEPENDS=	libgee-0.8.so:devel/libgee \
		libfribidi.so:converters/fribidi \
		libenchant-2.so:textproc/enchant2 \
		libtepl-6.so:x11-toolkits/tepl6 \
		libgspell-1.so:textproc/gspell

USES=		compiler:c11 desktop-file-utils gettext gmake gnome \
		pkgconfig tar:xz tex vala:build
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_GNOME=	cairo dconf intltool gtksourceview4
USE_TEX=	latex dvipsk
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS
NLS_USES=	gettext-runtime
NLS_CONFIGURE_ENABLE=	nls
OPTIONS_SUB=	yes

GLIB_SCHEMAS=	org.gnome.gnome-latex.gschema.xml

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

.include <bsd.port.post.mk>
