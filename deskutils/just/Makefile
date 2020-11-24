# $FreeBSD$

PORTNAME=	just
DISTVERSIONPREFIX=	v
DISTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just a command runner: handy way to save/run project-specific commands

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	casey

CARGO_CRATES=	aho-corasick-0.7.14 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cc-1.0.61 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		ctor-0.1.16 \
		ctrlc-3.1.7 \
		derivative-2.1.1 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		dotenv-0.15.0 \
		edit-distance-2.1.0 \
		env_logger-0.8.1 \
		executable-path-1.0.0 \
		getrandom-0.1.15 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		humantime-2.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		log-0.4.11 \
		memchr-2.3.3 \
		nix-0.18.0 \
		output_vt100-0.1.2 \
		ppv-lite86-0.2.9 \
		pretty_assertions-0.6.1 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.57 \
		regex-1.4.1 \
		regex-syntax-0.6.20 \
		remove_dir_all-0.5.3 \
		snafu-0.6.9 \
		snafu-derive-0.6.9 \
		strsim-0.8.0 \
		strum-0.19.5 \
		strum_macros-0.19.4 \
		syn-1.0.48 \
		target-1.0.0 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thiserror-1.0.21 \
		thiserror-impl-1.0.21 \
		thread_local-1.0.1 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		which-4.0.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
