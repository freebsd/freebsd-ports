# $FreeBSD$

PORTNAME=	bingrep
PORTVERSION=	g20171111
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Grep through binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	m4b
GH_TAGNAME=	a1ac993e44260bcd3b152a5a274ee386e264e479
GH_TUPLE=	m4b:goblin:3575947292644797dd81b471ab4ac4cb88615a9a:goblin \
		m4b:metagoblin:308e7d7ec3b1c61b859ff1b46e021178eac187f4:metagoblin

CARGO_CRATES=	aho-corasick-0.6.3 \
		ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		byteorder-1.1.0 \
		clap-2.26.0 \
		csv-0.15.0 \
		encode_unicode-0.3.1 \
		env_logger-0.4.3 \
		fuchsia-zircon-0.2.1 \
		fuchsia-zircon-sys-0.2.0 \
		hexplay-0.2.0 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		libc-0.2.40 \
		log-0.3.8 \
		memchr-1.0.1 \
		memrange-0.1.3 \
		plain-0.2.1 \
		prettytable-rs-0.6.7 \
		quote-0.3.15 \
		rand-0.3.18 \
		redox_syscall-0.1.31 \
		regex-0.2.2 \
		regex-syntax-0.4.1 \
		rustc-demangle-0.1.5 \
		rustc-serialize-0.3.24 \
		scroll-0.7.0 \
		scroll_derive-0.8.0 \
		strsim-0.6.0 \
		structopt-0.0.5 \
		structopt-derive-0.0.5 \
		syn-0.11.11 \
		synom-0.11.3 \
		term-0.4.6 \
		term_size-0.3.0 \
		termcolor-0.3.2 \
		textwrap-0.7.0 \
		theban_interval_tree-0.7.1 \
		thread_local-0.3.4 \
		time-0.1.38 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		wincolor-0.1.4
CARGO_USE_GITHUB=	yes
CARGO_GH_CARGOTOML=	${WRKSRC}/Cargo.toml ${WRKSRC_metagoblin}/Cargo.toml

PLIST_FILES=	bin/bingrep

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bingrep

.include <bsd.port.mk>
