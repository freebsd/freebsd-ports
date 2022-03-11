PORTNAME=	just
DISTVERSION=	1.1.0
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just a command runner: handy way to save/run project-specific commands

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	casey

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		camino-1.0.7 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		cradle-0.2.1 \
		ctor-0.1.21 \
		ctrlc-3.2.1 \
		derivative-2.2.0 \
		diff-0.1.12 \
		doc-comment-0.3.3 \
		dotenv-0.15.0 \
		edit-distance-2.1.0 \
		either-1.6.1 \
		env_logger-0.9.0 \
		executable-path-1.0.0 \
		fastrand-1.7.0 \
		heck-0.3.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		humantime-2.1.0 \
		instant-0.1.12 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		lexiclean-0.0.1 \
		libc-0.2.119 \
		linked-hash-map-0.5.4 \
		log-0.4.14 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		nix-0.23.1 \
		output_vt100-0.1.3 \
		pretty_assertions-1.1.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quote-1.0.15 \
		redox_syscall-0.2.11 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rustversion-1.0.6 \
		ryu-1.0.9 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		similar-2.1.0 \
		snafu-0.7.0 \
		snafu-derive-0.7.0 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		strum-0.24.0 \
		strum_macros-0.24.0 \
		syn-1.0.86 \
		target-2.0.0 \
		tempfile-3.3.0 \
		temptree-0.2.0 \
		term_size-0.3.2 \
		termcolor-1.1.3 \
		textwrap-0.11.0 \
		typed-arena-2.0.1 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		which-4.2.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5
PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
