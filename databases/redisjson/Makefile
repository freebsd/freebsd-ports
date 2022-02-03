# Created by: Sergey A. Osokin <osa@FreeBSD.org>

PORTNAME=	redisjson
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.6
PORTREVISION=	2
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
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

CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		array_tool-1.0.3 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.63 \
		bindgen-0.59.2 \
		bitflags-1.3.2 \
		bson-0.14.1 \
		byteorder-1.4.3 \
		cc-1.0.72 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clang-sys-1.3.0 \
		clap-2.34.0 \
		dashmap-4.0.2 \
		either-1.6.1 \
		enum-primitive-derive-0.1.2 \
		env_logger-0.9.0 \
		getrandom-0.1.16 \
		gimli-0.26.1 \
		glob-0.3.0 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		hex-0.3.2 \
		humantime-2.1.0 \
		ijson-0.1.3 \
		indexmap-1.7.0 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.112 \
		libloading-0.7.2 \
		linked-hash-map-0.5.4 \
		log-0.4.14 \
		md5-0.6.1 \
		memchr-2.4.1 \
		minimal-lexical-0.2.1 \
		miniz_oxide-0.4.4 \
		nom-7.1.0 \
		num-integer-0.1.44 \
		num-traits-0.1.43 \
		num-traits-0.2.14 \
		num_cpus-1.13.0 \
		object-0.27.1 \
		peeking_take_while-0.1.2 \
		ppv-lite86-0.2.15 \
		proc-macro2-1.0.33 \
		quote-0.3.15 \
		quote-1.0.10 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redis-module-0.25.0 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rustc-demangle-0.1.21 \
		rustc-hash-1.1.0 \
		rustversion-1.0.6 \
		ryu-1.0.9 \
		serde-1.0.131 \
		serde_derive-1.0.131 \
		serde_json-1.0.73 \
		shlex-1.1.0 \
		strsim-0.8.0 \
		strum_macros-0.23.1 \
		syn-0.11.11 \
		syn-1.0.82 \
		synom-0.11.3 \
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
		which-4.2.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		jsonpath_lib@git+https://github.com/RedisJSON/jsonpath.git?branch=generic_json_path\#198043336123efdb71172af9f5aef18ef5ec2d6b

PLIST_FILES=	lib/librejson.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/${CARGO_BUILD_TARGET}/*/librejson.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
