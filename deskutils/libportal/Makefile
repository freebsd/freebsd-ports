PORTNAME=	libportal
PORTVERSION=	0.6
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	GIO-styled async APIs for Flatpak
WWW=		https://github.com/flatpak/libportal

LICENSE=	GPLv2+

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

USES=		gnome meson pkgconfig qt:5

USE_GNOME=	glib20 gtk30 introspection:build
USE_QT=		buildtools core gui qmake:build testlib widgets x11extras
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flatpak

OPTIONS_DEFINE=		VAPI
OPTIONS_DEFAULT=	VAPI

VAPI_MESON_TRUE=	vapi
VAPI_USES=		vala:build

# docs require a port for gi-docgen
MESON_ARGS=	-Ddocs=false '-Dbackends=["qt5", "gtk3"]'
OPTIONS_SUB=	yes

.include <bsd.port.mk>
