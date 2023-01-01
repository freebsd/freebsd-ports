PORTNAME=	snazy
DISTVERSION=	0.9.1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Snazzy json log viewer
WWW=		https://github.com/chmouel/snazy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmouel

CARGO_CRATES=	aho-corasick-0.7.18 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-3.1.17 \
		clap_complete-3.1.4 \
		clap_derive-3.1.7 \
		clap_lex-0.2.0 \
		fastrand-1.7.0 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		indexmap-1.8.1 \
		instant-0.1.12 \
		itoa-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.125 \
		memchr-2.5.0 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		os_str_bytes-6.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.38 \
		quote-1.0.18 \
		redox_syscall-0.2.13 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		ryu-1.0.9 \
		serde-1.0.137 \
		serde_derive-1.0.137 \
		serde_json-1.0.81 \
		strsim-0.10.0 \
		syn-1.0.92 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		textwrap-0.15.0 \
		time-0.1.44 \
		unicode-xid-0.2.3 \
		version_check-0.9.4 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
