# $FreeBSD$

PORTNAME=	just
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.11
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just a command runner: handy way to save/run project-specific commands

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	casey

CARGO_CRATES=	addr2line-0.12.1 \
		aho-corasick-0.7.10 \
		ansi_term-0.11.0 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		backtrace-0.3.48 \
		bitflags-1.2.1 \
		cc-1.0.54 \
		cfg-if-0.1.10 \
		clap-2.33.1 \
		ctor-0.1.14 \
		ctrlc-3.1.4 \
		derivative-2.1.1 \
		difference-2.0.0 \
		doc-comment-0.3.3 \
		dotenv-0.15.0 \
		edit-distance-2.1.0 \
		env_logger-0.7.1 \
		executable-path-1.0.0 \
		failure-0.1.8 \
		getrandom-0.1.14 \
		gimli-0.21.0 \
		hermit-abi-0.1.13 \
		humantime-1.3.0 \
		lazy_static-1.4.0 \
		libc-0.2.70 \
		log-0.4.8 \
		memchr-2.3.3 \
		nix-0.17.0 \
		object-0.19.0 \
		output_vt100-0.1.2 \
		ppv-lite86-0.2.8 \
		pretty_assertions-0.6.1 \
		proc-macro2-1.0.17 \
		quick-error-1.2.3 \
		quote-1.0.6 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.16 \
		snafu-0.6.8 \
		snafu-derive-0.6.8 \
		strsim-0.8.0 \
		syn-1.0.23 \
		target-1.0.0 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		textwrap-0.11.0 \
		thread_local-1.0.1 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		vec_map-0.8.2 \
		void-1.0.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		which-3.1.1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
