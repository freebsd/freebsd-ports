PORTNAME=	libgusb
PORTVERSION=	0.3.9
CATEGORIES=	devel

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GUsb is a GObject wrapper for libusb1

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtk-doc>0:textproc/gtk-doc \
		vapigen:lang/vala

USES=		gnome meson pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	hughsie

USE_GNOME=	glib20 introspection:build

OPTIONS_DEFINE=		DOCS VALA
OPTIONS_DEFAULT=	DOCS VALA
OPTIONS_SUB=		yes

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MDOCS}
MESON_ARGS+=	-Ddocs=false
.endif
.if !${PORT_OPTIONS:MVALA}
MESON_ARGS+=	-Dvala=false
.endif

.include <bsd.port.mk>
