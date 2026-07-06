PORTNAME=	rizin
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.1
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
		libblake3.so:devel/libblake3 \
		libmspack.so:archivers/libmspack \
		libxxhash.so:devel/xxhash \
		libpcre2-8.so:devel/pcre2 \
		libtree-sitter.so:devel/tree-sitter \
		liblz4.so:archivers/liblz4 \
		libzip.so:archivers/libzip \
		libzstd.so:archivers/zstd \
		libZydis.so:devel/zydis

USES=		cmake:indirect localbase meson pkgconfig python:build

USE_GITHUB=	yes
GH_ACCOUNT=	rizinorg
GH_TUPLE=	rizinorg:rz-libdemangle:e633061e901208a20ed90f8aaf0b64f25caf73eb:libdemangle/subprojects/libdemangle \
		rizinorg:rizin-grammar-c:6a9d542145c2c783230ee4f9006bb81e3fbea635:rizin_grammar_c/subprojects/rizin-grammar-c \
		rizinorg:softfloat:537d18e7:rizin_softfloat/subprojects/softfloat \
		BLAKE2:BLAKE2:ed1974ea83433eba7b2d95c5dcd9ac33cb847913:blake2/subprojects/blake2

MESON_ARGS=	-D use_sys_blake3=enabled \
		-D use_sys_capstone=enabled \
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
		-D use_sys_zydis=enabled

PLIST_SUB=	SOVERSION=${PORTVERSION}

OPTIONS_DEFINE=	TEST
TEST_DESC=	Download binaries needed for testing
TEST_GH_TUPLE=	rizinorg:rizin-testbins:7f54b4970d413fe163f4f09dcfd9a328376133f0:test_bins/test/bins

post-extract:
	${CP} -r ${WRKSRC}/subprojects/packagefiles/blake2 ${WRKSRC}/subprojects
	${CP} -r ${WRKSRC}/subprojects/packagefiles/rizin-grammar-c ${WRKSRC}/subprojects

.include <bsd.port.mk>
