PORTNAME=	diesel
DISTVERSIONPREFIX=	v
DISTVERSION=	2.2.12
CATEGORIES=	databases
PKGNAMESUFFIX=	-cli

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Extensible ORM and Query Builder for Rust
WWW=		https://diesel.rs \
		https://github.com/diesel-rs/diesel

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo mysql pgsql sqlite

USE_GITHUB=	yes
GH_ACCOUNT=	diesel-rs

CARGO_BUILD_ARGS=	--package=diesel_cli
CARGO_INSTALL_PATH=	diesel_cli
CARGO_CRATES=	aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		anstream-0.6.19 \
		anstyle-1.0.11 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.3 \
		anstyle-wincon-3.0.9 \
		argon2-0.5.3 \
		assert_matches-1.5.0 \
		autocfg-1.5.0 \
		base64ct-1.8.0 \
		bigdecimal-0.4.8 \
		bitflags-2.9.1 \
		blake2-0.10.6 \
		block-buffer-0.10.4 \
		bumpalo-3.19.0 \
		byteorder-1.5.0 \
		cc-1.2.29 \
		cfg-if-1.0.1 \
		chrono-0.4.41 \
		clap-4.5.41 \
		clap_builder-4.5.41 \
		clap_complete-4.5.55 \
		clap_derive-4.5.41 \
		clap_lex-0.7.5 \
		cmake-0.1.54 \
		colorchoice-1.0.4 \
		console-0.15.11 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.17 \
		crypto-common-0.1.6 \
		darling-0.20.11 \
		darling_core-0.20.11 \
		darling_macro-0.20.11 \
		deranged-0.4.0 \
		diffy-0.4.2 \
		digest-0.10.7 \
		displaydoc-0.2.5 \
		dotenvy-0.15.7 \
		either-1.15.0 \
		encode_unicode-1.0.0 \
		env_logger-0.8.4 \
		equivalent-1.0.2 \
		errno-0.3.13 \
		fastrand-2.3.0 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		generic-array-0.14.7 \
		getrandom-0.2.16 \
		getrandom-0.3.3 \
		hashbrown-0.15.4 \
		heck-0.5.0 \
		iana-time-zone-0.1.63 \
		iana-time-zone-haiku-0.1.2 \
		icu_collections-2.0.0 \
		icu_locale_core-2.0.0 \
		icu_normalizer-2.0.0 \
		icu_normalizer_data-2.0.0 \
		icu_properties-2.0.1 \
		icu_properties_data-2.0.1 \
		icu_provider-2.0.0 \
		ident_case-1.0.1 \
		idna-1.0.3 \
		idna_adapter-1.2.1 \
		indexmap-2.10.0 \
		insta-1.43.1 \
		ipnet-2.11.0 \
		ipnetwork-0.21.1 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.15 \
		js-sys-0.3.77 \
		lazy_static-1.5.0 \
		libc-0.2.174 \
		libm-0.2.15 \
		libsqlite3-sys-0.35.0 \
		link-cplusplus-1.0.10 \
		linux-raw-sys-0.9.4 \
		litemap-0.8.0 \
		lock_api-0.4.13 \
		log-0.4.27 \
		matchers-0.1.0 \
		memchr-2.7.5 \
		mysqlclient-src-0.1.4+9.3.0 \
		mysqlclient-sys-0.4.7 \
		nu-ansi-term-0.46.0 \
		nu-ansi-term-0.50.1 \
		num-bigint-0.4.6 \
		num-conv-0.1.0 \
		num-integer-0.1.46 \
		num-traits-0.2.19 \
		once_cell-1.21.3 \
		once_cell_polyfill-1.70.1 \
		openssl-src-300.5.1+3.5.1 \
		openssl-sys-0.9.109 \
		overload-0.1.1 \
		parking_lot-0.12.4 \
		parking_lot_core-0.9.11 \
		password-hash-0.5.0 \
		percent-encoding-2.3.1 \
		pin-project-lite-0.2.16 \
		pkg-config-0.3.32 \
		potential_utf-0.1.2 \
		powerfmt-0.2.0 \
		ppv-lite86-0.2.21 \
		pq-src-0.3.9+libpq-17.5 \
		pq-sys-0.7.2 \
		proc-macro2-1.0.95 \
		quickcheck-1.0.3 \
		quote-1.0.40 \
		r-efi-5.3.0 \
		r2d2-0.8.10 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.5.13 \
		regex-1.11.1 \
		regex-automata-0.1.10 \
		regex-automata-0.4.9 \
		regex-syntax-0.6.29 \
		regex-syntax-0.8.5 \
		rustix-1.0.7 \
		rustversion-1.0.21 \
		ryu-1.0.20 \
		scheduled-thread-pool-0.2.7 \
		scopeguard-1.2.0 \
		semver-1.0.26 \
		serde-1.0.219 \
		serde_derive-1.0.219 \
		serde_json-1.0.140 \
		serde_regex-1.1.0 \
		serde_spanned-1.0.0 \
		sharded-slab-0.1.7 \
		shlex-1.3.0 \
		similar-2.7.0 \
		smallvec-1.15.1 \
		stable_deref_trait-1.2.0 \
		strsim-0.11.1 \
		subtle-2.6.1 \
		syn-2.0.104 \
		synstructure-0.13.2 \
		tempfile-3.20.0 \
		thiserror-2.0.12 \
		thiserror-impl-2.0.12 \
		thread_local-1.1.9 \
		time-0.3.41 \
		time-core-0.1.4 \
		time-macros-0.2.22 \
		tinystr-0.8.1 \
		toml-0.9.2 \
		toml_datetime-0.7.0 \
		toml_parser-1.0.1 \
		toml_writer-1.0.2 \
		tracing-0.1.41 \
		tracing-attributes-0.1.30 \
		tracing-core-0.1.34 \
		tracing-log-0.2.0 \
		tracing-subscriber-0.3.19 \
		typenum-1.18.0 \
		unicode-ident-1.0.18 \
		url-2.5.4 \
		utf8_iter-1.0.4 \
		utf8parse-0.2.2 \
		uuid-1.17.0 \
		valuable-0.1.1 \
		vcpkg-0.2.15 \
		version_check-0.9.5 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasi-0.14.2+wasi-0.2.4 \
		wasm-bindgen-0.2.100 \
		wasm-bindgen-backend-0.2.100 \
		wasm-bindgen-macro-0.2.100 \
		wasm-bindgen-macro-support-0.2.100 \
		wasm-bindgen-shared-0.2.100 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.61.2 \
		windows-implement-0.60.0 \
		windows-interface-0.59.1 \
		windows-link-0.1.3 \
		windows-result-0.3.4 \
		windows-strings-0.4.2 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-sys-0.60.2 \
		windows-targets-0.52.6 \
		windows-targets-0.53.2 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_gnullvm-0.53.0 \
		windows_aarch64_msvc-0.52.6 \
		windows_aarch64_msvc-0.53.0 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnu-0.53.0 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_gnullvm-0.53.0 \
		windows_i686_msvc-0.52.6 \
		windows_i686_msvc-0.53.0 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnu-0.53.0 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_gnullvm-0.53.0 \
		windows_x86_64_msvc-0.52.6 \
		windows_x86_64_msvc-0.53.0 \
		winnow-0.7.12 \
		wit-bindgen-rt-0.39.0 \
		writeable-0.6.1 \
		yoke-0.8.0 \
		yoke-derive-0.8.0 \
		zerocopy-0.8.26 \
		zerocopy-derive-0.8.26 \
		zerofrom-0.1.6 \
		zerofrom-derive-0.1.6 \
		zerotrie-0.2.2 \
		zerovec-0.11.2 \
		zerovec-derive-0.11.1

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${CP} ${FILESDIR}/bindings_8_0_35_powerpc64_freebsd.rs \
		${WRKSRC}/cargo-crates/mysqlclient-sys-0.4.7/bindings/

.include <bsd.port.mk>
