PORTNAME=	ods2sql
DISTVERSION=	0.4.0
PORTREVISION=	43
CATEGORIES=	databases

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Create SQLite3 database from ODS spreadsheet
WWW=		https://gitlab.com/zetok/ods2sql

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo sqlite

USE_GITLAB=	yes
GL_ACCOUNT=	zetok
GL_TAGNAME=	aca63183274038487cecb6be17d7f65e92178b8c

CARGO_CRATES=	adler32-1.2.0 \
		ahash-0.4.6 \
		aho-corasick-0.7.14 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		byteorder-1.3.4 \
		calamine-0.16.2 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		clap-3.0.0-beta.2 \
		clap_derive-3.0.0-beta.2 \
		codepage-0.1.1 \
		crc32fast-1.2.1 \
		encoding_rs-0.8.24 \
		env_logger-0.8.1 \
		fallible-iterator-0.2.0 \
		fallible-streaming-iterator-0.1.9 \
		flate2-1.0.14 \
		hashbrown-0.9.1 \
		hashlink-0.6.0 \
		heck-0.3.1 \
		hermit-abi-0.1.17 \
		humantime-2.0.1 \
		indexmap-1.6.0 \
		lazy_static-1.4.0 \
		libc-0.2.79 \
		libsqlite3-sys-0.20.1 \
		log-0.4.11 \
		memchr-2.3.3 \
		miniz_oxide-0.3.7 \
		os_str_bytes-2.3.2 \
		pkg-config-0.3.19 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.24 \
		quick-xml-0.19.0 \
		quote-1.0.7 \
		regex-1.4.1 \
		regex-syntax-0.6.20 \
		rusqlite-0.24.1 \
		serde-1.0.117 \
		smallvec-1.4.2 \
		strsim-0.10.0 \
		syn-1.0.46 \
		termcolor-1.1.0 \
		textwrap-0.12.1 \
		thiserror-1.0.21 \
		thiserror-impl-1.0.21 \
		thread_local-1.0.1 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vcpkg-0.2.10 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zip-0.5.8

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
