PORTNAME=	dura
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.0
PORTREVISION=	28
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Background process that watches Git repositories and backs up data
WWW=		https://github.com/tkellogg/dura

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo ssl

USE_GITHUB=	yes
GH_ACCOUNT=	tkellogg

CARGO_CRATES=	ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		bytes-1.1.0 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-3.1.6 \
		dirs-4.0.0 \
		dirs-sys-0.3.6 \
		fastrand-1.6.0 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		git2-0.13.25 \
		hashbrown-0.11.2 \
		hermit-abi-0.1.19 \
		idna-0.2.3 \
		indexmap-1.8.0 \
		instant-0.1.12 \
		itoa-1.0.1 \
		jobserver-0.1.24 \
		lazy_static-1.4.0 \
		libc-0.2.112 \
		libgit2-sys-0.12.26+1.3.0 \
		libssh2-sys-0.2.23 \
		libz-sys-1.1.3 \
		lock_api-0.4.5 \
		log-0.4.14 \
		matchers-0.1.0 \
		matches-0.1.9 \
		memchr-2.4.1 \
		mio-0.7.14 \
		miow-0.3.7 \
		ntapi-0.3.6 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		num_cpus-1.13.1 \
		once_cell-1.9.0 \
		openssl-probe-0.1.4 \
		openssl-sys-0.9.72 \
		os_str_bytes-6.0.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		percent-encoding-2.1.0 \
		pin-project-lite-0.2.8 \
		pkg-config-0.3.24 \
		proc-macro2-1.0.36 \
		quote-1.0.14 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		ryu-1.0.9 \
		scopeguard-1.1.0 \
		serde-1.0.133 \
		serde_derive-1.0.133 \
		serde_json-1.0.74 \
		serial_test-0.5.1 \
		serial_test_derive-0.5.1 \
		sharded-slab-0.1.4 \
		signal-hook-registry-1.4.0 \
		smallvec-1.7.0 \
		strsim-0.10.0 \
		syn-1.0.85 \
		tempfile-3.3.0 \
		termcolor-1.1.2 \
		textwrap-0.15.0 \
		thread_local-1.1.4 \
		time-0.1.44 \
		tinyvec-1.5.1 \
		tinyvec_macros-0.1.0 \
		tokio-1.15.0 \
		tokio-macros-1.7.0 \
		toml-0.5.8 \
		tracing-0.1.29 \
		tracing-attributes-0.1.18 \
		tracing-core-0.1.21 \
		tracing-log-0.1.2 \
		tracing-subscriber-0.3.5 \
		unicode-bidi-0.3.7 \
		unicode-normalization-0.1.19 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		vcpkg-0.2.15 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
