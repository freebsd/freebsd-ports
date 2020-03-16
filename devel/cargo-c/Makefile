# $FreeBSD$

PORTNAME=	cargo-c
DISTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
# XXX Teach USES=cargo to have proper default
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Cargo C-ABI helpers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
PLIST_FILES=	bin/cargo-cbuild \
		bin/cargo-cinstall

CARGO_CRATES=	aho-corasick-0.7.8 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		c2-chacha-0.2.3 \
		cargo_metadata-0.9.1 \
		cbindgen-0.13.1 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		env_logger-0.7.1 \
		getrandom-0.1.14 \
		heck-0.3.1 \
		hermit-abi-0.1.7 \
		humantime-1.3.0 \
		itoa-0.4.5 \
		lazy_static-1.4.0 \
		libc-0.2.67 \
		log-0.4.8 \
		memchr-2.3.3 \
		ppv-lite86-0.2.6 \
		pretty_env_logger-0.4.0 \
		proc-macro-error-0.4.9 \
		proc-macro-error-attr-0.4.9 \
		proc-macro2-1.0.8 \
		quick-error-1.2.3 \
		quote-1.0.2 \
		rand-0.7.3 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.3.4 \
		regex-syntax-0.6.14 \
		remove_dir_all-0.5.2 \
		rustversion-1.0.2 \
		ryu-1.0.2 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.104 \
		serde_derive-1.0.104 \
		serde_json-1.0.48 \
		strsim-0.8.0 \
		structopt-0.3.9 \
		structopt-derive-0.4.2 \
		syn-1.0.15 \
		syn-mid-0.5.0 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		toml-0.5.6 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.1 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.3 \
		winapi-x86_64-pc-windows-gnu-0.4.0

post-patch:
	@${REINPLACE_CMD} -e 's,libdir.join("pkgconfig,prefix.join("libdata/pkgconfig,' \
		${WRKSRC}/src/main.rs

.include <bsd.port.mk>
