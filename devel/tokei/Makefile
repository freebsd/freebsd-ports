# $FreeBSD$

PORTNAME=	tokei
DISTVERSIONPREFIX=	v
DISTVERSION=	8.0.1
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Display statistics about your code

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENCE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENCE-MIT

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	Aaronepower

CARGO_CRATES=	aho-corasick-0.6.6 \
		ansi_term-0.11.0 \
		arrayvec-0.4.7 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		byteorder-1.2.4 \
		cfg-if-0.1.5 \
		clap-2.32.0 \
		crossbeam-0.3.2 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		dtoa-0.4.3 \
		either-1.5.0 \
		encoding_rs-0.8.6 \
		encoding_rs_io-0.1.2 \
		env_logger-0.5.12 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		globset-0.4.1 \
		half-1.1.2 \
		handlebars-1.0.1 \
		hex-0.3.2 \
		humantime-1.1.1 \
		ignore-0.4.3 \
		itoa-0.4.2 \
		kernel32-sys-0.2.2 \
		lazy_static-1.1.0 \
		libc-0.2.43 \
		linked-hash-map-0.5.1 \
		log-0.4.4 \
		memchr-2.0.1 \
		memoffset-0.2.1 \
		nodrop-0.1.12 \
		num_cpus-1.8.0 \
		pest-1.0.6 \
		pest_derive-1.0.8 \
		proc-macro2-0.4.13 \
		quick-error-1.2.2 \
		quote-0.3.15 \
		quote-0.6.8 \
		rand-0.4.3 \
		rayon-1.0.2 \
		rayon-core-1.4.1 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-1.0.2 \
		regex-syntax-0.6.2 \
		remove_dir_all-0.5.1 \
		ryu-0.2.5 \
		same-file-1.0.2 \
		scopeguard-0.3.3 \
		serde-1.0.74 \
		serde_cbor-0.9.0 \
		serde_derive-1.0.74 \
		serde_json-1.0.26 \
		serde_yaml-0.8.1 \
		strsim-0.7.0 \
		syn-0.11.11 \
		syn-0.14.9 \
		synom-0.11.3 \
		tempdir-0.3.7 \
		term_size-0.3.1 \
		termcolor-1.0.1 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		toml-0.4.6 \
		ucd-util-0.1.1 \
		unicode-width-0.1.5 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.1 \
		version_check-0.1.4 \
		walkdir-2.2.2 \
		winapi-0.2.8 \
		winapi-0.3.5 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.0 \
		yaml-rust-0.4.0
CARGO_FEATURES=	all # enable all output serialization formats

PLIST_FILES=	bin/tokei

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tokei

.include <bsd.port.mk>
