# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	wayland
PORTVERSION=	1.18.0
PORTREVISION=	3
CATEGORIES=	graphics wayland
MASTER_SITES=	https://wayland.freedesktop.org/releases/

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES+=	0fc00fff3015.diff:-p1 # https://gitlab.freedesktop.org/wayland/wayland/merge_requests/60
PATCHFILES+=	1283d54dac97.diff:-p1 # https://gitlab.freedesktop.org/wayland/wayland/merge_requests/61
PATCHFILES+=	3a3dd0820de3.diff:-p1 # https://gitlab.freedesktop.org/wayland/wayland/merge_requests/61
PATCHFILES+=	230885ebb40b.diff:-p1 # https://gitlab.freedesktop.org/wayland/wayland/merge_requests/61

MAINTAINER=	x11@FreeBSD.org
COMMENT=	Wayland composite "server"

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libffi.so:devel/libffi \
		libepoll-shim.so:devel/libepoll-shim

CFLAGS+=	"-I${LOCALBASE}/include/libepoll-shim"

USES=		meson pkgconfig tar:xz
USE_GNOME=	libxslt:build
USE_LDCONFIG=	yes
MESON_ARGS=	-Ddocumentation=false

.include <bsd.port.mk>
