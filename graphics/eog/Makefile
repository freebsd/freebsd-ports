PORTNAME=	eog
DISTVERSION=	49.3
PORTREVISION=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Eye Of Gnome image viewer
WWW=		https://gitlab.gnome.org/GNOME/eog

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		itstool:textproc/itstool
LIB_DEPENDS=	libexif.so:graphics/libexif \
		libhandy-1.so:x11-toolkits/libhandy \
		liblcms2.so:graphics/lcms2 \
		libpeas-gtk-1.0.so:devel/libpeas1
RUN_DEPENDS=	gsettings-desktop-schemas>=0:devel/gsettings-desktop-schemas \
		${PYTHON_PKGNAMEPREFIX}libpeas1>0:devel/py-libpeas1@${PY_FLAVOR}

USES=		compiler:c++11-lang desktop-file-utils gettext-tools gnome \
		jpeg localbase meson pkgconfig python shared-mime-info \
		tar:xz xorg
USE_GNOME=	cairo gnomedesktop3 gtk30 introspection librsvg2
GLIB_SCHEMAS=	org.gnome.eog.enums.xml \
		org.gnome.eog.gschema.xml
USE_XORG=	x11

MESON_ARGS=	-Dlibportal=false

PORTSCOUT=	limit:^49\.

PLIST_SUB+=	VERSION=3.0

OPTIONS_DEFINE=		EXEMPI
OPTIONS_DEFAULT=	EXEMPI
OPTIONS_SUB=		yes

EXEMPI_DESC=		XMP support
EXEMPI_LIB_DEPENDS=	libexempi.so:textproc/exempi
EXEMPI_MESON_TRUE=	xmp

.include <bsd.port.mk>
