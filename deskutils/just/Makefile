PORTNAME=	just
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.3
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just a command runner: handy way to save/run project-specific commands

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	casey

CARGO_CRATES=	aho-corasick-0.7.18 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cc-1.0.67 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		ctor-0.1.20 \
		ctrlc-3.1.9 \
		derivative-2.2.0 \
		diff-0.1.12 \
		doc-comment-0.3.3 \
		dotenv-0.15.0 \
		edit-distance-2.1.0 \
		either-1.6.1 \
		env_logger-0.8.3 \
		executable-path-1.0.0 \
		getrandom-0.2.2 \
		heck-0.3.2 \
		hermit-abi-0.1.18 \
		humantime-2.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.94 \
		log-0.4.14 \
		memchr-2.4.0 \
		nix-0.20.0 \
		output_vt100-0.1.2 \
		ppv-lite86-0.2.10 \
		pretty_assertions-0.7.2 \
		proc-macro2-1.0.26 \
		quote-1.0.9 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.2 \
		rand_hc-0.3.0 \
		redox_syscall-0.2.8 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		snafu-0.6.10 \
		snafu-derive-0.6.10 \
		strsim-0.8.0 \
		strum-0.20.0 \
		strum_macros-0.20.1 \
		syn-1.0.72 \
		target-1.0.0 \
		tempfile-3.2.0 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		which-4.1.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
