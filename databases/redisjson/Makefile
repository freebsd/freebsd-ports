# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	redisjson
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.4
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	osa@FreeBSD.org
COMMENT=	JSON data type for Redis

LICENSE=	UNKNOWN
LICENSE_NAME=	Redis Source Available License Agreement
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

BUILD_DEPENDS=	${LOCALBASE}/llvm${LLVM_DEFAULT}/lib/libclang.so:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	RedisJSON
GH_PROJECT=	RedisJSON

CARGO_CRATES=	addr2line-0.15.2 \
		adler-1.0.2 \
		aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		array_tool-1.0.3 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.59 \
		bindgen-0.59.1 \
		bitflags-1.3.2 \
		bitvec-0.19.5 \
		bson-0.14.1 \
		byteorder-1.4.3 \
		cc-1.0.71 \
		cexpr-0.5.0 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clang-sys-1.2.2 \
		clap-2.33.3 \
		either-1.6.1 \
		enum-primitive-derive-0.1.2 \
		env_logger-0.8.4 \
		funty-1.1.0 \
		getrandom-0.1.16 \
		gimli-0.24.0 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.3.2 \
		humantime-2.1.0 \
		indexmap-1.7.0 \
		itertools-0.10.1 \
		itoa-0.4.8 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.106 \
		libloading-0.7.1 \
		linked-hash-map-0.5.4 \
		log-0.4.14 \
		md5-0.6.1 \
		memchr-2.3.4 \
		miniz_oxide-0.4.4 \
		nom-6.2.1 \
		num-integer-0.1.44 \
		num-traits-0.1.43 \
		num-traits-0.2.14 \
		object-0.24.0 \
		peeking_take_while-0.1.2 \
		ppv-lite86-0.2.15 \
		proc-macro2-1.0.32 \
		quote-0.3.15 \
		quote-1.0.10 \
		radium-0.5.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redis-module-0.24.0 \
		regex-1.4.6 \
		regex-syntax-0.6.25 \
		rustc-demangle-0.1.21 \
		rustc-hash-1.1.0 \
		ryu-1.0.5 \
		serde-1.0.130 \
		serde_derive-1.0.130 \
		serde_json-1.0.68 \
		shlex-1.1.0 \
		strsim-0.8.0 \
		strum_macros-0.22.0 \
		syn-0.11.11 \
		syn-1.0.81 \
		synom-0.11.3 \
		tap-1.0.1 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		time-0.1.44 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.0.4 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		which-3.1.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wyz-0.2.0 \
		jsonpath_lib@git+https://github.com/RedisJSON/jsonpath.git?tag=v2.0.2\#ee220247038dd3a0605a54e65011d1fbceb42dee

PLIST_FILES=	lib/librejson.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/librejson.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
