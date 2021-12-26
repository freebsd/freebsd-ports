PORTNAME=	libportal
PORTVERSION=	0.5
CATEGORIES=	deskutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	GIO-styled async APIs for Flatpak

LICENSE=	GPLv2+

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

USES=		gnome meson pkgconfig qt:5

USE_GNOME=	glib20 gtk30 introspection:build
USE_QT=		core gui qmake_build widgets x11extras
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	flatpak

OPTIONS_DEFINE=		VALA
OPTIONS_DEFAULT=	VALA

VALA_MESON_TRUE=	vapi
VALA_BUILD_DEPENDS=	vapigen:lang/vala
VALA_DESC=		Install Vala language bindings

# docs require a port for gi-docgen
MESON_ARGS=	-Ddocs=false '-Dbackends=["qt5", "gtk3"]'
OPTIONS_SUB=	yes

.include <bsd.port.mk>
