PORTNAME=	snazy
DISTVERSION=	0.52.17
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Snazzy json log viewer
WWW=		https://github.com/chmouel/snazy

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	chmouel

CARGO_CRATES=	aho-corasick-1.1.2 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.11 \
		anstyle-1.0.4 \
		anstyle-parse-0.2.3 \
		anstyle-query-1.0.2 \
		anstyle-wincon-3.0.2 \
		autocfg-1.1.0 \
		bitflags-1.3.2 \
		bitflags-2.4.2 \
		bumpalo-3.14.0 \
		cc-1.0.83 \
		cfg-if-1.0.0 \
		chrono-0.4.32 \
		clap-4.4.18 \
		clap_builder-4.4.18 \
		clap_complete-4.4.9 \
		clap_derive-4.4.7 \
		clap_lex-0.6.0 \
		color-print-0.3.5 \
		color-print-proc-macro-0.3.5 \
		colorchoice-1.0.0 \
		core-foundation-sys-0.8.6 \
		errno-0.3.8 \
		fastrand-2.0.1 \
		heck-0.4.1 \
		hermit-abi-0.3.4 \
		iana-time-zone-0.1.59 \
		iana-time-zone-haiku-0.1.2 \
		is-terminal-0.4.10 \
		itoa-1.0.10 \
		js-sys-0.3.67 \
		libc-0.2.152 \
		linux-raw-sys-0.4.13 \
		log-0.4.20 \
		memchr-2.7.1 \
		minimal-lexical-0.2.1 \
		nom-7.1.3 \
		num-traits-0.2.17 \
		once_cell-1.19.0 \
		proc-macro2-1.0.78 \
		quote-1.0.35 \
		redox_syscall-0.4.1 \
		regex-1.10.3 \
		regex-automata-0.4.4 \
		regex-syntax-0.8.2 \
		rustix-0.38.30 \
		ryu-1.0.16 \
		serde-1.0.195 \
		serde_derive-1.0.195 \
		serde_json-1.0.111 \
		strsim-0.10.0 \
		syn-1.0.109 \
		syn-2.0.48 \
		tempfile-3.9.0 \
		unicode-ident-1.0.12 \
		utf8parse-0.2.1 \
		wasm-bindgen-0.2.90 \
		wasm-bindgen-backend-0.2.90 \
		wasm-bindgen-macro-0.2.90 \
		wasm-bindgen-macro-support-0.2.90 \
		wasm-bindgen-shared-0.2.90 \
		windows-core-0.52.0 \
		windows-sys-0.52.0 \
		windows-targets-0.52.0 \
		windows_aarch64_gnullvm-0.52.0 \
		windows_aarch64_msvc-0.52.0 \
		windows_i686_gnu-0.52.0 \
		windows_i686_msvc-0.52.0 \
		windows_x86_64_gnu-0.52.0 \
		windows_x86_64_gnullvm-0.52.0 \
		windows_x86_64_msvc-0.52.0 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
