PORTNAME=	snazy
DISTVERSION=	0.54.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Snazzy json log viewer
WWW=		https://github.com/chmouel/snazy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmouel

CARGO_CRATES=	aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.15 \
		anstyle-1.0.8 \
		anstyle-parse-0.2.5 \
		anstyle-query-1.1.1 \
		anstyle-wincon-3.0.4 \
		autocfg-1.4.0 \
		bitflags-2.6.0 \
		bumpalo-3.16.0 \
		cc-1.1.24 \
		cfg-if-1.0.0 \
		chrono-0.4.38 \
		clap-4.5.19 \
		clap_builder-4.5.19 \
		clap_complete-4.5.32 \
		clap_derive-4.5.18 \
		clap_lex-0.7.2 \
		color-print-0.3.6 \
		color-print-proc-macro-0.3.6 \
		colorchoice-1.0.2 \
		core-foundation-sys-0.8.7 \
		errno-0.3.9 \
		fastrand-2.1.1 \
		heck-0.5.0 \
		hermit-abi-0.4.0 \
		iana-time-zone-0.1.61 \
		iana-time-zone-haiku-0.1.2 \
		is-terminal-0.4.13 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.11 \
		js-sys-0.3.70 \
		libc-0.2.159 \
		linux-raw-sys-0.4.14 \
		log-0.4.22 \
		memchr-2.7.4 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.19 \
		once_cell-1.20.1 \
		portable-atomic-1.9.0 \
		proc-macro2-1.0.86 \
		quote-1.0.37 \
		regex-1.11.0 \
		regex-automata-0.4.8 \
		regex-syntax-0.8.5 \
		rustix-0.38.37 \
		ryu-1.0.18 \
		serde-1.0.210 \
		serde_derive-1.0.210 \
		serde_json-1.0.128 \
		shlex-1.3.0 \
		strsim-0.11.1 \
		syn-2.0.79 \
		tempfile-3.13.0 \
		unicode-ident-1.0.13 \
		utf8parse-0.2.2 \
		wasm-bindgen-0.2.93 \
		wasm-bindgen-backend-0.2.93 \
		wasm-bindgen-macro-0.2.93 \
		wasm-bindgen-macro-support-0.2.93 \
		wasm-bindgen-shared-0.2.93 \
		windows-core-0.52.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		yansi-1.0.1

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
