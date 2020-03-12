# $FreeBSD$

PORTNAME=	delta
DISTVERSION=	0.0.16
PORTREVISION=	2
CATEGORIES=	devel
PKGNAMEPREFIX=	git-

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Syntax-highlighting pager for git/diff

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	dandavison

LIB_DEPENDS+=	libonig.so:devel/oniguruma

CARGO_CRATES=	adler32-1.0.3 \
		aho-corasick-0.7.6 \
		ansi_term-0.11.0 \
		arrayref-0.3.5 \
		arrayvec-0.5.1 \
		atty-0.2.13 \
		autocfg-0.1.5 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		base64-0.10.1 \
		bincode-1.1.4 \
		bitflags-1.1.0 \
		blake2b_simd-0.5.9 \
		box_drawing-0.1.2 \
		byteorder-1.3.2 \
		cc-1.0.38 \
		cfg-if-0.1.9 \
		clap-2.33.0 \
		clicolors-control-1.0.0 \
		cloudabi-0.0.3 \
		console-0.7.7 \
		constant_time_eq-0.1.4 \
		crc32fast-1.2.0 \
		crossbeam-utils-0.6.6 \
		dirs-2.0.2 \
		dirs-sys-0.3.4 \
		either-1.5.2 \
		encode_unicode-0.3.5 \
		error-chain-0.12.1 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		flate2-1.0.9 \
		fnv-1.0.6 \
		fuchsia-cprng-0.1.1 \
		heck-0.3.1 \
		humantime-1.2.0 \
		itertools-0.8.0 \
		itoa-0.4.4 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		libc-0.2.60 \
		line-wrap-0.1.1 \
		linked-hash-map-0.5.2 \
		lock_api-0.3.1 \
		memchr-2.2.1 \
		miniz-sys-0.1.12 \
		miniz_oxide-0.2.2 \
		miniz_oxide_c_api-0.2.2 \
		onig-4.3.2 \
		onig_sys-69.1.0 \
		parking_lot-0.9.0 \
		parking_lot_core-0.6.2 \
		pkg-config-0.3.15 \
		plist-0.4.2 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.6 \
		quick-error-1.2.2 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_os-0.1.3 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.1 \
		regex-1.2.1 \
		regex-syntax-0.6.11 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		rustc_version-0.2.3 \
		ryu-1.0.0 \
		safemem-0.3.1 \
		same-file-1.0.5 \
		scopeguard-1.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.98 \
		serde_derive-1.0.98 \
		serde_json-1.0.40 \
		shell-words-0.1.0 \
		smallvec-0.6.10 \
		strsim-0.8.0 \
		structopt-0.2.18 \
		structopt-derive-0.2.18 \
		syn-0.15.43 \
		syn-1.0.11 \
		synstructure-0.12.3 \
		syntect-3.2.0 \
		termios-0.3.1 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		walkdir-2.2.9 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xml-rs-0.8.0 \
		yaml-rust-0.4.3

CONFLICTS_INSTALL=	devel/delta
PLIST_FILES=		bin/delta

OPTIONS_DEFINE=		BASH
OPTIONS_DEFAULT=	BASH
BASH_PLIST_FILES=	etc/bash_completion.d/_delta.bash

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/delta

do-install-BASH-on:
	${MKDIR} ${STAGEDIR}${LOCALBASE}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/completion/bash/completion.sh \
			${STAGEDIR}${LOCALBASE}/etc/bash_completion.d/_delta.bash

.include <bsd.port.mk>
