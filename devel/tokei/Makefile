# $FreeBSD$

PORTNAME=	tokei
DISTVERSIONPREFIX=	v
DISTVERSION=	6.1.2
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

CARGO_CRATES=	aho-corasick-0.6.3 \
		ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		byteorder-1.1.0 \
		clap-2.26.0 \
		coco-0.1.1 \
		conv-0.3.3 \
		crossbeam-0.2.10 \
		custom_derive-0.1.7 \
		dtoa-0.4.2 \
		either-1.1.0 \
		encoding-0.2.33 \
		encoding-index-japanese-1.20141219.5 \
		encoding-index-korean-1.20141219.5 \
		encoding-index-simpchinese-1.20141219.5 \
		encoding-index-singlebyte-1.20141219.5 \
		encoding-index-tradchinese-1.20141219.5 \
		encoding_index_tests-0.1.4 \
		env_logger-0.4.3 \
		errln-0.1.0 \
		fnv-1.0.5 \
		futures-0.1.15 \
		globset-0.2.0 \
		handlebars-0.27.0 \
		hex-0.2.0 \
		ignore-0.2.2 \
		itoa-0.3.3 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		libc-0.2.30 \
		linked-hash-map-0.3.0 \
		linked-hash-map-0.4.2 \
		log-0.3.8 \
		magenta-0.1.1 \
		magenta-sys-0.1.1 \
		memchr-1.0.1 \
		num-traits-0.1.40 \
		num_cpus-1.6.2 \
		pest-0.3.3 \
		quick-error-1.2.0 \
		quote-0.3.15 \
		rand-0.3.16 \
		rayon-0.7.1 \
		rayon-core-1.2.1 \
		regex-0.2.2 \
		regex-syntax-0.4.1 \
		same-file-0.1.3 \
		scopeguard-0.3.2 \
		serde-1.0.11 \
		serde_bytes-0.10.1 \
		serde_cbor-0.6.1 \
		serde_derive-1.0.11 \
		serde_derive_internals-0.15.1 \
		serde_json-1.0.2 \
		serde_yaml-0.7.1 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		tempdir-0.3.5 \
		term_size-0.3.0 \
		textwrap-0.7.0 \
		thread_local-0.3.4 \
		toml-0.4.5 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unreachable-1.0.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		walkdir-1.0.7 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		yaml-rust-0.3.5

PLIST_FILES=	bin/tokei

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/tokei

.include <bsd.port.mk>
