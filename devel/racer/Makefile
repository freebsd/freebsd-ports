# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	racer
DISTVERSION=	2.0.10
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	beyert@cs.ucr.edu
COMMENT=	Rust code completion helper

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	racer-rust

PLIST_FILES=	bin/racer

CARGO_CRATES=	aho-corasick-0.5.3 \
		ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.7.0 \
		bitflags-0.8.2 \
		clap-2.24.2 \
		clippy-0.0.103 \
		clippy_lints-0.0.103 \
		env_logger-0.3.5 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		libc-0.2.40 \
		log-0.3.7 \
		matches-0.1.4 \
		memchr-0.1.11 \
		nom-1.2.4 \
		quine-mc_cluskey-0.2.4 \
		rand-0.3.15 \
		regex-0.1.80 \
		regex-syntax-0.3.9 \
		rustc-serialize-0.3.24 \
		semver-0.2.3 \
		strsim-0.6.0 \
		syntex_errors-0.52.0 \
		syntex_pos-0.52.0 \
		syntex_syntax-0.52.0 \
		term-0.4.5 \
		term_size-0.3.0 \
		thread-id-2.0.0 \
		thread_local-0.2.7 \
		toml-0.1.30 \
		toml-0.2.1 \
		typed-arena-1.3.0 \
		unicode-normalization-0.1.4 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.3 \
		utf8-ranges-0.1.3 \
		vec_map-0.8.0 \
		winapi-0.2.8 \
		winapi-build-0.1.1

.include <bsd.port.mk>
