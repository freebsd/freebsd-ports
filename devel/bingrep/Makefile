# $FreeBSD$

PORTNAME=	bingrep
PORTVERSION=	0.6.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Grep through binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		argon2rs-0.2.5 \
		arrayvec-0.4.10 \
		atty-0.2.11 \
		autocfg-0.1.2 \
		backtrace-0.3.15 \
		backtrace-sys-0.1.28 \
		bitflags-1.0.4 \
		blake2-rfc-0.2.18 \
		byteorder-1.3.1 \
		cc-1.0.35 \
		cfg-if-0.1.7 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		constant_time_eq-0.1.3 \
		cpp_demangle-0.2.12 \
		csv-1.0.7 \
		csv-core-0.1.5 \
		dirs-1.0.5 \
		encode_unicode-0.3.5 \
		env_logger-0.6.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		glob-0.2.11 \
		goblin-0.0.21 \
		heck-0.3.1 \
		hexplay-0.2.1 \
		humantime-1.2.0 \
		itoa-0.4.3 \
		lazy_static-1.3.0 \
		libc-0.2.51 \
		log-0.4.6 \
		memchr-2.2.0 \
		memrange-0.1.3 \
		metagoblin-0.1.2 \
		nodrop-0.1.13 \
		plain-0.2.3 \
		prettytable-rs-0.8.0 \
		proc-macro2-0.4.27 \
		quick-error-1.2.2 \
		quote-0.6.12 \
		rand-0.3.23 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rand_os-0.1.3 \
		rdrand-0.4.0 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		redox_users-0.3.0 \
		regex-1.1.6 \
		regex-syntax-0.6.6 \
		rustc-demangle-0.1.14 \
		rustc-serialize-0.3.24 \
		rustc_version-0.2.3 \
		ryu-0.2.7 \
		scoped_threadpool-0.1.9 \
		scroll-0.9.2 \
		scroll_derive-0.9.5 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.90 \
		strsim-0.8.0 \
		structopt-0.2.15 \
		structopt-derive-0.2.15 \
		syn-0.15.31 \
		synstructure-0.10.1 \
		term-0.5.2 \
		termcolor-0.3.6 \
		termcolor-1.0.4 \
		termion-1.5.1 \
		textwrap-0.11.0 \
		theban_interval_tree-0.7.1 \
		thread_local-0.3.6 \
		time-0.1.42 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.2 \
		vec_map-0.8.1 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6 \
		wincolor-1.0.1

PLIST_FILES=	bin/bingrep

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bingrep

.include <bsd.port.mk>
