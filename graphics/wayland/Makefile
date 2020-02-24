# Created by: kwm@FreeBSD.org
# $FreeBSD$

PORTNAME=	wayland
PORTVERSION=	1.18.0
PORTREVISION=	1
CATEGORIES=	graphics wayland
MASTER_SITES=	https://wayland.freedesktop.org/releases/

PATCH_SITES=	https://gitlab.freedesktop.org/${PORTNAME}/${PORTNAME}/commit/
PATCHFILES+=	0fc00fff3015.patch:-p1 # https://gitlab.freedesktop.org/wayland/wayland/merge_requests/60

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

post-patch:
# posix_fallocate returns EINVAL on ZFS since FreeBSD 12.0
	@${REINPLACE_CMD} '/posix_fallocate/d' ${WRKSRC}/meson.build

.include <bsd.port.mk>
