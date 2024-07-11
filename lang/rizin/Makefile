PORTNAME=	rizin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.3
PORTREVISION=	1
CATEGORIES=	lang security shells

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	UNIX-like reverse engineering framework and command-line toolset
WWW=		https://rizin.re/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3 =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3 =	${WRKSRC}/COPYING.LESSER

NOT_FOR_ARCHS=	armv6 armv7

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyyaml>=0:devel/py-pyyaml@${PY_FLAVOR}
LIB_DEPENDS=	libcapstone.so:devel/capstone \
		libmspack.so:archivers/libmspack \
		libxxhash.so:devel/xxhash \
		libpcre2-8.so:devel/pcre2 \
		libtree-sitter.so:devel/tree-sitter \
		liblz4.so:archivers/liblz4 \
		libzip.so:archivers/libzip \
		libzstd.so:archivers/zstd

USES=		localbase meson pkgconfig python:build

USE_GITHUB=	yes
GH_ACCOUNT=	rizinorg
GH_TUPLE=	rizinorg:rz-libdemangle:0031d1a:libdemangle/subprojects/libdemangle \
		rizinorg:tree-sitter-c:81d96d8:tree_sitter_c/subprojects/tree-sitter-c \
		BLAKE3-team:BLAKE3:54930c9:blake3/subprojects/blake3

MESON_ARGS=	-D use_sys_capstone=enabled \
		-D use_sys_magic=enabled \
		-D use_sys_libzip=enabled \
		-D use_sys_zlib=enabled \
		-D use_sys_lz4=enabled \
		-D use_sys_lzma=enabled \
		-D use_sys_xxhash=enabled \
		-D use_sys_pcre2=enabled \
		-D use_sys_libmspack=enabled \
		-D use_sys_tree_sitter=enabled \
		-D enable_rz_test=false \
		-D use_sys_libzstd=enabled \

TESTING_UNSAFE=	requires additional test input files

post-extract:
	${CP} -r ${WRKSRC}/subprojects/packagefiles/blake3 ${WRKSRC}/subprojects
	${CP} -r ${WRKSRC}/subprojects/packagefiles/tree-sitter-c ${WRKSRC}/subprojects
	${CP} ${WRKSRC}/librz/debug/p/native/linux/reg/linux-ppc64.h ${WRKSRC}/librz/debug/p/native/reg/kfbsd-ppc64.h

.include <bsd.port.mk>
