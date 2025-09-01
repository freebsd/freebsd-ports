PORTNAME=	frece
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.6
PORTREVISION=	24
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Maintain a database sorted by frecency (frequency + recency)
WWW=		https://github.com/YodaEmbedding/frece

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	YodaEmbedding

CARGO_CRATES=	addr2line-0.15.2 \
		adler-1.0.2 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		backtrace-0.3.60 \
		bitflags-1.2.1 \
		cc-1.0.69 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		failure-0.1.8 \
		failure_derive-0.1.8 \
		fs2-0.4.3 \
		gimli-0.24.0 \
		hermit-abi-0.1.19 \
		libc-0.2.98 \
		memchr-2.4.0 \
		miniz_oxide-0.4.4 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		object-0.25.3 \
		proc-macro2-1.0.28 \
		quote-1.0.9 \
		rustc-demangle-0.1.20 \
		strsim-0.8.0 \
		syn-1.0.74 \
		synstructure-0.12.5 \
		textwrap-0.11.0 \
		time-0.1.44 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
