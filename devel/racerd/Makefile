# Created by: Richard Gallamore <ultima@FreeBSD.org>
# $FreeBSD$

PORTNAME=	racerd
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.1-56
DISTVERSIONSUFFIX=	-g29cd4c6
PORTREVISION=	8
CATEGORIES=	devel

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Rust semantic analysis server powered by Racer

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jwilm

PLIST_FILES=	bin/racerd

CARGO_CRATES=	aho-corasick-0.5.3 \
		ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		bodyparser-0.4.1 \
		clap-2.26.0 \
		conduit-mime-types-0.7.3 \
		constant_time_eq-0.1.3 \
		conv-0.3.3 \
		cookie-0.2.5 \
		custom_derive-0.1.7 \
		docopt-0.6.86 \
		dtoa-0.2.2 \
		env_logger-0.3.5 \
		error-0.1.9 \
		gcc-0.3.54 \
		hpack-0.2.0 \
		httparse-1.2.3 \
		hyper-0.9.18 \
		idna-0.1.4 \
		iron-0.4.0 \
		iron-hmac-0.4.0 \
		itoa-0.1.1 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-0.1.16 \
		lazy_static-0.2.8 \
		libc-0.2.49 \
		log-0.3.8 \
		logger-0.1.0 \
		magenta-0.1.1 \
		magenta-sys-0.1.1 \
		matches-0.1.6 \
		memchr-0.1.11 \
		mime-0.2.6 \
		modifier-0.1.0 \
		num-traits-0.1.40 \
		num_cpus-0.2.13 \
		num_cpus-1.6.2 \
		percent-encoding-1.0.0 \
		persistent-0.2.1 \
		plugin-0.2.6 \
		quote-0.3.15 \
		racer-2.0.10 \
		rand-0.3.16 \
		redox_syscall-0.1.31 \
		regex-0.1.80 \
		regex-syntax-0.3.9 \
		route-recognizer-0.1.12 \
		router-0.2.0 \
		rust-crypto-0.2.36 \
		rustc-serialize-0.3.24 \
		serde-0.8.23 \
		serde_codegen-0.8.23 \
		serde_codegen_internals-0.11.3 \
		serde_json-0.8.6 \
		solicit-0.4.4 \
		strsim-0.5.2 \
		strsim-0.6.0 \
		syn-0.10.8 \
		syntex-0.54.0 \
		syntex_errors-0.52.0 \
		syntex_errors-0.54.0 \
		syntex_pos-0.52.0 \
		syntex_pos-0.54.0 \
		syntex_syntax-0.52.0 \
		syntex_syntax-0.54.0 \
		term-0.4.6 \
		term_size-0.3.0 \
		textwrap-0.7.0 \
		thread-id-2.0.0 \
		thread_local-0.2.7 \
		time-0.1.38 \
		toml-0.2.1 \
		traitobject-0.0.1 \
		traitobject-0.1.0 \
		typeable-0.1.2 \
		typed-arena-1.3.0 \
		typemap-0.3.3 \
		unicase-1.4.2 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.5 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.3 \
		unicode-xid-0.0.4 \
		unsafe-any-0.4.2 \
		url-1.5.1 \
		utf8-ranges-0.1.3 \
		vec_map-0.8.0 \
		version_check-0.1.3 \
		winapi-0.2.8 \
		winapi-build-0.1.1

.include <bsd.port.mk>
