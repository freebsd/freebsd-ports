PORTNAME=	xls2txt
DISTVERSION=	1.0.1
PORTREVISION=	42
CATEGORIES=	databases textproc

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Utilities to convert spreadsheet files to text and csv formats
WWW=		https://github.com/masklinn/xls2txt

LICENSE=	APACHE20

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	masklinn
GH_TAGNAME=	1222f8069428f6bcedfcccf9e80523db34c0d343

CARGO_CRATES=	adler32-1.2.0 \
		ansi_term-0.11.0 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		bstr-0.2.14 \
		byteorder-1.3.4 \
		calamine-0.16.2 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-2.33.3 \
		codepage-0.1.1 \
		crc32fast-1.2.1 \
		csv-1.1.5 \
		csv-core-0.1.10 \
		encoding_rs-0.8.26 \
		flate2-1.0.14 \
		hermit-abi-0.1.17 \
		itoa-0.4.6 \
		lazy_static-1.4.0 \
		libc-0.2.80 \
		log-0.4.11 \
		memchr-2.3.4 \
		miniz_oxide-0.3.7 \
		proc-macro2-1.0.24 \
		quick-xml-0.19.0 \
		quote-1.0.7 \
		regex-automata-0.1.9 \
		ryu-1.0.5 \
		serde-1.0.117 \
		strsim-0.8.0 \
		syn-1.0.52 \
		textwrap-0.11.0 \
		thiserror-1.0.22 \
		thiserror-impl-1.0.22 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zip-0.5.8

EXECUTABLES=	${PORTNAME} xls2csv

PLIST_FILES=	${EXECUTABLES:S/^/bin\//}

CONFLICTS_INSTALL=	catdoc libxls p5-Spreadsheet-Read

.include <bsd.port.mk>
