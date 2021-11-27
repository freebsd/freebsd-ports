PORTNAME=	yj
DISTVERSION=	1.1.34
CATEGORIES=	converters textproc
PKGNAMESUFFIX=	-${GH_ACCOUNT}

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Command line tool that converts YAML to JSON

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	bruceadams
CARGO_CRATES=	addr2line-0.16.0 \
		adler-1.0.2 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.62 \
		bitflags-1.3.2 \
		cc-1.0.71 \
		cfg-if-1.0.0 \
		clap-3.0.0-beta.5 \
		clap_derive-3.0.0-beta.5 \
		doc-comment-0.3.3 \
		dtoa-0.4.8 \
		exitfailure-0.5.1 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		gimli-0.25.0 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		indexmap-1.7.0 \
		itoa-0.4.8 \
		lazy_static-1.4.0 \
		libc-0.2.106 \
		linked-hash-map-0.5.4 \
		memchr-2.4.1 \
		miniz_oxide-0.4.4 \
		object-0.27.1 \
		os_str_bytes-4.2.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.32 \
		quote-1.0.10 \
		rustc-demangle-0.1.21 \
		ryu-1.0.5 \
		serde-1.0.130 \
		serde_json-1.0.68 \
		serde_yaml-0.8.21 \
		snafu-0.6.10 \
		snafu-derive-0.6.10 \
		strsim-0.10.0 \
		syn-1.0.81 \
		synstructure-0.12.6 \
		termcolor-1.1.2 \
		terminal_size-0.1.17 \
		textwrap-0.14.2 \
		unicase-2.6.0 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		version_check-0.9.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/yj

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
