# $FreeBSD$

PORTNAME=	tokei
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.2
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

CARGO_CRATES=	aho-corasick-0.6.4 \
		ansi_term-0.11.0 \
		arrayvec-0.4.7 \
		atty-0.2.9 \
		bitflags-1.0.1 \
		byteorder-1.2.2 \
		cfg-if-0.1.2 \
		clap-2.31.2 \
		crossbeam-0.3.2 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		dtoa-0.4.2 \
		either-1.5.0 \
		encoding-0.2.33 \
		encoding-index-japanese-1.20141219.5 \
		encoding-index-korean-1.20141219.5 \
		encoding-index-simpchinese-1.20141219.5 \
		encoding-index-singlebyte-1.20141219.5 \
		encoding-index-tradchinese-1.20141219.5 \
		encoding_index_tests-0.1.4 \
		env_logger-0.5.9 \
		fnv-1.0.6 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		globset-0.4.0 \
		handlebars-0.32.0 \
		hex-0.3.2 \
		humantime-1.1.1 \
		ignore-0.4.2 \
		itoa-0.4.1 \
		lazy_static-1.0.0 \
		libc-0.2.40 \
		linked-hash-map-0.5.1 \
		log-0.4.1 \
		memchr-2.0.1 \
		memoffset-0.2.1 \
		nodrop-0.1.12 \
		num-traits-0.1.43 \
		num-traits-0.2.2 \
		num_cpus-1.8.0 \
		pest-1.0.6 \
		pest_derive-1.0.7 \
		proc-macro2-0.3.6 \
		quick-error-1.2.1 \
		quote-0.3.15 \
		quote-0.5.2 \
		rand-0.4.2 \
		rayon-1.0.1 \
		rayon-core-1.4.0 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		regex-0.2.10 \
		regex-syntax-0.5.5 \
		remove_dir_all-0.5.1 \
		same-file-1.0.2 \
		scopeguard-0.3.3 \
		serde-1.0.42 \
		serde_cbor-0.8.2 \
		serde_derive-1.0.42 \
		serde_derive_internals-0.23.1 \
		serde_json-1.0.16 \
		serde_yaml-0.7.3 \
		strsim-0.7.0 \
		syn-0.11.11 \
		syn-0.13.1 \
		synom-0.11.3 \
		tempdir-0.3.7 \
		termcolor-0.3.6 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		toml-0.4.6 \
		ucd-util-0.1.1 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		walkdir-2.1.4 \
		winapi-0.3.4 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6 \
		yaml-rust-0.4.0
CARGO_FEATURES=	all # enable all output serialization formats

PLIST_FILES=	bin/tokei

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tokei

.include <bsd.port.mk>
