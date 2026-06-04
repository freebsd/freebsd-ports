PORTNAME=	git-repo-manager
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Git tool to manage worktrees and integrate with GitHub and GitLab
WWW=		https://hakoerber.github.io/git-repo-manager/ \
		https://github.com/hakoerber/git-repo-manager/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase

USE_GITHUB=	yes
GH_ACCOUNT=	hakoerber

RUSTFLAGS=	${ARCH:S/i386/YES/:C/^[a-z].*//:S/YES/-C target-feature=+sse,+sse2/} # add sse sse2 target-features only on i386

CARGO_CRATES=	aho-corasick-1.1.4 \
		anstream-1.0.0 \
		anstyle-1.0.14 \
		anstyle-parse-1.0.0 \
		anstyle-query-1.1.5 \
		anstyle-wincon-3.0.11 \
		autocfg-1.5.0 \
		base64-0.22.1 \
		bitflags-2.11.1 \
		bytes-1.11.1 \
		camino-1.2.2 \
		cc-1.2.62 \
		cfg-if-1.0.4 \
		clap-4.6.1 \
		clap_builder-4.6.0 \
		clap_derive-4.6.1 \
		clap_lex-1.1.0 \
		colorchoice-1.0.5 \
		comfy-table-7.2.2 \
		console-0.16.3 \
		cookie-0.18.1 \
		cookie_store-0.22.0 \
		deranged-0.5.5 \
		displaydoc-0.2.5 \
		document-features-0.2.11 \
		encode_unicode-1.0.0 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		fastrand-2.4.1 \
		find-msvc-tools-0.1.9 \
		form_urlencoded-1.2.2 \
		getrandom-0.2.17 \
		getrandom-0.3.4 \
		git2-0.21.0 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		http-1.4.0 \
		httparse-1.10.1 \
		icu_collections-2.1.1 \
		icu_locale_core-2.1.1 \
		icu_normalizer-2.1.1 \
		icu_normalizer_data-2.1.1 \
		icu_properties-2.1.2 \
		icu_properties_data-2.1.2 \
		icu_provider-2.1.1 \
		idna-1.1.0 \
		idna_adapter-1.2.1 \
		indexmap-2.14.0 \
		is_terminal_polyfill-1.70.2 \
		itoa-1.0.18 \
		jobserver-0.1.34 \
		lazy_static-1.5.0 \
		libc-0.2.186 \
		libgit2-sys-0.18.4+1.9.3 \
		libssh2-sys-0.3.1 \
		libz-sys-1.1.28 \
		linux-raw-sys-0.12.1 \
		litemap-0.8.2 \
		litrs-0.4.2 \
		lock_api-0.4.13 \
		log-0.4.29 \
		memchr-2.8.0 \
		num-conv-0.1.0 \
		once_cell-1.21.4 \
		once_cell_polyfill-1.70.2 \
		openssl-probe-0.1.6 \
		openssl-src-300.5.1+3.5.1 \
		openssl-sys-0.9.116 \
		parking_lot-0.12.4 \
		parking_lot_core-0.9.11 \
		parse_link_header-0.4.1 \
		percent-encoding-2.3.2 \
		pkg-config-0.3.33 \
		potential_utf-0.1.5 \
		powerfmt-0.2.0 \
		proc-macro2-1.0.106 \
		quote-1.0.45 \
		r-efi-5.3.0 \
		redox_syscall-0.5.17 \
		regex-1.12.3 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.10 \
		ring-0.17.14 \
		rustix-1.1.4 \
		rustls-0.23.40 \
		rustls-pki-types-1.14.1 \
		rustls-webpki-0.103.13 \
		ryu-1.0.20 \
		scopeguard-1.2.0 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.149 \
		serde_spanned-1.1.1 \
		serde_yaml-0.9.34+deprecated \
		shellexpand-3.1.2 \
		shlex-1.3.0 \
		smallvec-1.15.1 \
		stable_deref_trait-1.2.1 \
		subtle-2.6.1 \
		syn-2.0.117 \
		synstructure-0.13.2 \
		temp-env-0.3.6 \
		tempfile-3.27.0 \
		thiserror-2.0.12 \
		thiserror-impl-2.0.12 \
		time-0.3.45 \
		time-core-0.1.7 \
		time-macros-0.2.25 \
		tinystr-0.8.3 \
		toml-1.1.2+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_parser-1.1.2+spec-1.1.0 \
		toml_writer-1.1.1+spec-1.1.0 \
		unicode-ident-1.0.24 \
		unicode-segmentation-1.13.2 \
		unicode-width-0.2.2 \
		unsafe-libyaml-0.2.11 \
		untrusted-0.9.0 \
		ureq-3.3.0 \
		ureq-proto-0.6.0 \
		url-2.5.8 \
		url-escape-0.1.1 \
		utf8-zero-0.8.1 \
		utf8_iter-1.0.4 \
		utf8parse-0.2.2 \
		vcpkg-0.2.15 \
		version_check-0.9.5 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.2+wasi-0.2.9 \
		webpki-roots-1.0.7 \
		windows-link-0.2.1 \
		windows-sys-0.52.0 \
		windows-sys-0.61.2 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-1.0.2 \
		wit-bindgen-0.51.0 \
		writeable-0.6.3 \
		yoke-0.8.2 \
		yoke-derive-0.8.2 \
		zerofrom-0.1.8 \
		zerofrom-derive-0.1.7 \
		zeroize-1.8.2 \
		zerotrie-0.2.4 \
		zerovec-0.11.6 \
		zerovec-derive-0.11.3 \
		zmij-1.0.21

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/grm

.include <bsd.port.mk>
