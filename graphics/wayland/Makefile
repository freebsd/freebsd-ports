# Created by: kwm@FreeBSD.org

PORTNAME=	wayland
PORTVERSION=	1.19.0
PORTREVISION=	1
CATEGORIES=	graphics wayland
MASTER_SITES=	https://wayland.freedesktop.org/releases/

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES+=	ed55438366e93d70867e3ba6b80978673e536fc0.patch:-p1 # MR 133

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland composite "server"

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libepoll-shim.so:devel/libepoll-shim

CFLAGS+=	"-I${LOCALBASE}/include/libepoll-shim"

USES=		cpe gnome meson pkgconfig tar:xz
USE_GNOME=	libxslt:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocumentation=false

.include <bsd.port.mk>
