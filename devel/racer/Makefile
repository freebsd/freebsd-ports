# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	racer
DISTVERSION=	2.0.14
CATEGORIES=	devel

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Rust code completion helper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	racer-rust

PLIST_FILES=	bin/racer

CARGO_CRATES=	aho-corasick-0.6.4 \
		ansi_term-0.11.0 \
		atty-0.2.8 \
		bitflags-0.7.0 \
		bitflags-1.0.1 \
		cfg-if-0.1.2 \
		clap-2.31.1 \
		clippy-0.0.103 \
		clippy_lints-0.0.103 \
		env_logger-0.5.5 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		humantime-1.1.1 \
		kernel32-sys-0.2.2 \
		lazy_static-1.0.0 \
		libc-0.2.39 \
		log-0.3.9 \
		log-0.4.1 \
		matches-0.1.6 \
		memchr-2.0.1 \
		nom-1.2.4 \
		quick-error-1.2.1 \
		quine-mc_cluskey-0.2.4 \
		rand-0.4.2 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		regex-0.2.10 \
		regex-syntax-0.3.9 \
		regex-syntax-0.5.3 \
		rustc-serialize-0.3.24 \
		semver-0.2.3 \
		serde-1.0.36 \
		strsim-0.7.0 \
		syntex_errors-0.52.0 \
		syntex_pos-0.52.0 \
		syntex_syntax-0.52.0 \
		term-0.4.6 \
		termcolor-0.3.5 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		toml-0.1.30 \
		toml-0.4.5 \
		ucd-util-0.1.1 \
		unicode-normalization-0.1.5 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.3 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6

.include <bsd.port.mk>
