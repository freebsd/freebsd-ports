PORTNAME=	jot
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
PORTREVISION=	20
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rapid note management for the terminal
WWW=		https://github.com/araekiel/jot

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	araekiel

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-3.2.22 \
		clap_derive-3.2.18 \
		clap_lex-0.2.4 \
		directories-4.0.1 \
		dirs-sys-0.3.7 \
		dunce-1.0.3 \
		fs_extra-1.2.0 \
		getrandom-0.2.7 \
		hashbrown-0.12.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.9.1 \
		libc-0.2.132 \
		once_cell-1.14.0 \
		os_str_bytes-6.3.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.43 \
		quote-1.0.21 \
		redox_syscall-0.2.16 \
		redox_users-0.4.3 \
		serde-1.0.144 \
		serde_derive-1.0.144 \
		strsim-0.10.0 \
		syn-1.0.99 \
		termcolor-1.1.3 \
		textwrap-0.15.1 \
		thiserror-1.0.35 \
		thiserror-impl-1.0.35 \
		toml-0.5.9 \
		unicode-ident-1.0.4 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/jt

.include <bsd.port.mk>
