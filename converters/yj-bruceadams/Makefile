PORTNAME=	yj
DISTVERSION=	1.2.0
PORTREVISION=	32
CATEGORIES=	converters textproc
PKGNAMESUFFIX=	-${GH_ACCOUNT}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command line tool that converts YAML to JSON
WWW=		https://github.com/bruceadams/yj

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bruceadams
CARGO_CRATES=	addr2line-0.17.0 \
		adler-1.0.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.63 \
		bitflags-1.3.2 \
		cc-1.0.72 \
		cfg-if-1.0.0 \
		clap-3.0.0 \
		clap_derive-3.0.0 \
		doc-comment-0.3.3 \
		exitfailure-0.5.1 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		gimli-0.26.1 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		indexmap-1.7.0 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.112 \
		linked-hash-map-0.5.4 \
		memchr-2.4.1 \
		miniz_oxide-0.4.4 \
		object-0.27.1 \
		os_str_bytes-6.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quote-1.0.14 \
		rustc-demangle-0.1.21 \
		ryu-1.0.9 \
		serde-1.0.133 \
		serde_json-1.0.74 \
		serde_yaml-0.8.23 \
		snafu-0.6.10 \
		snafu-derive-0.6.10 \
		strsim-0.10.0 \
		syn-1.0.84 \
		synstructure-0.12.6 \
		termcolor-1.1.2 \
		terminal_size-0.1.17 \
		textwrap-0.14.2 \
		unicode-segmentation-1.8.0 \
		unicode-xid-0.2.2 \
		version_check-0.9.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

CONFLICTS_INSTALL=	yj

PLIST_FILES=	bin/yj

.include <bsd.port.mk>
