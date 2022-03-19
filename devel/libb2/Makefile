# Created by: Martin Matuska <mm@FreeBSD.org>

PORTNAME=	libb2
DISTVERSIONPREFIX=	v
DISTVERSION=	0.98.1
PORTREVISION=	1
CATEGORIES=	devel

PATCH_SITES=	https://github.com/eli-schwartz/libb2/commit/
PATCHFILES=	9fbedd0db42305c904fc28deb9c69c7fc8f3d870.patch:-p1 \
		2c6ffd80d5e785dfba356ad47198ced0577e3483.patch:-p1

MAINTAINER=	mm@FreeBSD.org
COMMENT=	C library providing BLAKE2b, BLAKE2s, BLAKE2bp, BLAKE2sp

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		meson
USE_GITHUB=	yes
USE_LDCONFIG=	yes

GH_ACCOUNT=	BLAKE2

PLIST_FILES=	include/blake2.h \
		lib/libb2.so \
		lib/libb2.so.1 \
		lib/libb2.so.1.0.4 \
		libdata/pkgconfig/libb2.pc

MESON_ARGS_amd64=	-Dfat=true -Dopenmp=enabled
MESON_ARGS_aarch64=	-Dopenmp=enabled
MESON_ARGS=		-Dnative=false -Dopenmp=disabled
MESON_ARGS+=		${MESON_ARGS_${ARCH}}

.include <bsd.port.mk>
