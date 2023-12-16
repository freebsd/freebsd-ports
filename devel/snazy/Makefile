PORTNAME=	snazy
DISTVERSION=	0.52.1
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Snazzy json log viewer
WWW=		https://github.com/chmouel/snazy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmouel

CARGO_CRATES=	aho-corasick-1.1.0 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.5.0 \
		anstyle-1.0.3 \
		anstyle-parse-0.2.1 \
		anstyle-query-1.0.0 \
		anstyle-wincon-2.1.0 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.4.0 \
		bumpalo-3.14.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		chrono-0.4.31 \
		clap-4.4.3 \
		clap_builder-4.4.2 \
		clap_complete-4.4.1 \
		clap_derive-4.4.2 \
		clap_lex-0.5.1 \
		color-print-0.3.5 \
		color-print-proc-macro-0.3.5 \
		colorchoice-1.0.0 \
		core-foundation-sys-0.8.4 \
		errno-0.3.3 \
		errno-dragonfly-0.1.2 \
		fastrand-2.0.0 \
		heck-0.4.1 \
		hermit-abi-0.3.2 \
		iana-time-zone-0.1.57 \
		iana-time-zone-haiku-0.1.2 \
		is-terminal-0.4.9 \
		itoa-1.0.9 \
		js-sys-0.3.64 \
		libc-0.2.148 \
		linux-raw-sys-0.4.7 \
		log-0.4.20 \
		memchr-2.6.3 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.16 \
		once_cell-1.18.0 \
		proc-macro2-1.0.67 \
		quote-1.0.33 \
		redox_syscall-0.3.5 \
		regex-1.9.5 \
		regex-automata-0.3.8 \
		regex-syntax-0.7.5 \
		rustix-0.38.13 \
		ryu-1.0.15 \
		serde-1.0.188 \
		serde_derive-1.0.188 \
		serde_json-1.0.107 \
		strsim-0.10.0 \
		syn-1.0.109 \
		syn-2.0.37 \
		tempfile-3.8.0 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		wasm-bindgen-0.2.87 \
		wasm-bindgen-backend-0.2.87 \
		wasm-bindgen-macro-0.2.87 \
		wasm-bindgen-macro-support-0.2.87 \
		wasm-bindgen-shared-0.2.87 \
		windows-0.48.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
