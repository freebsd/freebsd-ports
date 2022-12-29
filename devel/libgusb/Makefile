PORTNAME=	libgusb
PORTVERSION=	0.3.10
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GUsb is a GObject wrapper for libusb1
WWW=		https://github.com/hughsie/libgusb

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc

USES=		gnome meson pkgconfig vala:build

USE_GITHUB=	yes
GH_ACCOUNT=	hughsie

USE_GNOME=	glib20 introspection:build

OPTIONS_DEFINE=		DOCS VAPI
OPTIONS_DEFAULT=	DOCS VAPI
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
MESON_ARGS+=	-Ddocs=false
.endif
.if !${PORT_OPTIONS:MVAPI}
MESON_ARGS+=	-Dvapi=false
.endif

.include <bsd.port.mk>
