PORTNAME=	rizin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.3
CATEGORIES=	lang security shells

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UNIX-like reverse engineering framework and command-line toolset
WWW=		https://rizin.re

LICENSE=	LGPL3 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=	armv6 armv7

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}
LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libmspack.so:archivers/libmspack \
		libxxhash.so:devel/xxhash \
		libtree-sitter.so:devel/tree-sitter \
		liblz4.so:archivers/liblz4 \
		libzip.so:archivers/libzip

USES=		localbase meson pkgconfig python:build ssl

MESON_ARGS=	-D use_sys_capstone=enabled \
		-D use_sys_magic=enabled \
		-D use_sys_libzip=enabled \
		-D use_sys_zlib=enabled \
		-D use_sys_lz4=enabled \
		-D use_sys_lzma=enabled \
		-D use_sys_xxhash=enabled \
		-D use_sys_openssl=enabled \
		-D use_sys_libmspack=enabled \
		-D use_sys_tree_sitter=enabled \
		-D enable_rz_test=false
		# -D use_sys_libzstd=enabled \

USE_GITHUB=	yes
GH_ACCOUNT=	rizinorg
GH_TUPLE=	rizinorg:rz-libdemangle:3eb0ef8:libdemangle/subprojects/libdemangle \
		rizinorg:tree-sitter-c:81d96d8:tree_sitter_c/subprojects/tree-sitter-c \
		BLAKE3-team:BLAKE3:3f396d2:blake3/subprojects/blake3

post-extract:
	${CP} -r ${WRKSRC}/subprojects/packagefiles/blake3 ${WRKSRC}/subprojects
	${CP} -r ${WRKSRC}/subprojects/packagefiles/tree-sitter-c ${WRKSRC}/subprojects

.include <bsd.port.mk>
