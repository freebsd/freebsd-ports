PORTNAME=	snazy
DISTVERSION=	0.50.0
PORTREVISION=	5
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Snazzy json log viewer
WWW=		https://github.com/chmouel/snazy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmouel

CARGO_CRATES=	aho-corasick-0.7.19 \
		android_system_properties-0.1.5 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bumpalo-3.11.0 \
		cfg-if-1.0.0 \
		chrono-0.4.22 \
		clap-4.0.9 \
		clap_complete-4.0.2 \
		clap_derive-4.0.9 \
		clap_lex-0.3.0 \
		core-foundation-sys-0.8.3 \
		fastrand-1.8.0 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		iana-time-zone-0.1.50 \
		instant-0.1.12 \
		itoa-1.0.3 \
		js-sys-0.3.60 \
		libc-0.2.134 \
		log-0.4.17 \
		memchr-2.5.0 \
		num-integer-0.1.45 \
		num-traits-0.2.15 \
		once_cell-1.15.0 \
		os_str_bytes-6.3.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.46 \
		quote-1.0.21 \
		redox_syscall-0.2.16 \
		regex-1.6.0 \
		regex-syntax-0.6.27 \
		remove_dir_all-0.5.3 \
		ryu-1.0.11 \
		serde-1.0.145 \
		serde_derive-1.0.145 \
		serde_json-1.0.85 \
		strsim-0.10.0 \
		syn-1.0.101 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		time-0.1.44 \
		unicode-ident-1.0.4 \
		version_check-0.9.4 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.83 \
		wasm-bindgen-backend-0.2.83 \
		wasm-bindgen-macro-0.2.83 \
		wasm-bindgen-macro-support-0.2.83 \
		wasm-bindgen-shared-0.2.83 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
