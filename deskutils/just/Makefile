PORTNAME=	just
DISTVERSION=	1.36.0
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just a command runner: handy way to save/run project-specific commands
WWW=		https://just.systems/ \
		https://github.com/casey/just

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: error[E0308]: mismatched types, see https://github.com/dotenv-rs/dotenv/issues/83

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	casey

CARGO_CRATES=	aho-corasick-1.1.3 \
		android-tzdata-0.1.1 \
		android_system_properties-0.1.5 \
		ansi_term-0.12.1 \
		anstream-0.6.15 \
		anstyle-1.0.8 \
		anstyle-parse-0.2.5 \
		anstyle-query-1.1.1 \
		anstyle-wincon-3.0.4 \
		arrayref-0.3.9 \
		arrayvec-0.7.6 \
		autocfg-1.4.0 \
		bitflags-2.6.0 \
		blake3-1.5.4 \
		block-buffer-0.10.4 \
		bstr-1.10.0 \
		bumpalo-3.16.0 \
		byteorder-1.5.0 \
		camino-1.1.9 \
		cc-1.1.23 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		chrono-0.4.38 \
		clap-4.5.18 \
		clap_builder-4.5.18 \
		clap_complete-4.5.29 \
		clap_derive-4.5.18 \
		clap_lex-0.7.2 \
		clap_mangen-0.2.23 \
		colorchoice-1.0.2 \
		constant_time_eq-0.3.1 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.14 \
		crossbeam-deque-0.8.5 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.20 \
		crypto-common-0.1.6 \
		ctrlc-3.4.5 \
		derivative-2.2.0 \
		diff-0.1.13 \
		digest-0.10.7 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		dotenvy-0.15.7 \
		edit-distance-2.1.3 \
		either-1.13.0 \
		errno-0.3.9 \
		executable-path-1.0.0 \
		fastrand-2.1.1 \
		generic-array-0.14.7 \
		getopts-0.2.21 \
		getrandom-0.2.15 \
		heck-0.5.0 \
		hermit-abi-0.3.9 \
		home-0.5.9 \
		iana-time-zone-0.1.61 \
		iana-time-zone-haiku-0.1.2 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.11 \
		js-sys-0.3.70 \
		lexiclean-0.0.1 \
		libc-0.2.159 \
		libredox-0.1.3 \
		linux-raw-sys-0.4.14 \
		log-0.4.22 \
		memchr-2.7.4 \
		memmap2-0.9.5 \
		nix-0.29.0 \
		num-traits-0.2.19 \
		num_cpus-1.16.0 \
		once_cell-1.20.1 \
		option-ext-0.2.0 \
		percent-encoding-2.3.1 \
		portable-atomic-1.9.0 \
		ppv-lite86-0.2.20 \
		pretty_assertions-1.4.1 \
		proc-macro2-1.0.86 \
		pulldown-cmark-0.9.6 \
		pulldown-cmark-to-cmark-10.0.4 \
		quote-1.0.37 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rayon-core-1.12.1 \
		redox_users-0.4.6 \
		regex-1.11.0 \
		regex-automata-0.4.8 \
		regex-syntax-0.8.5 \
		roff-0.2.2 \
		rustix-0.38.37 \
		rustversion-1.0.17 \
		ryu-1.0.18 \
		semver-1.0.23 \
		serde-1.0.210 \
		serde_derive-1.0.210 \
		serde_json-1.0.128 \
		sha2-0.10.8 \
		shellexpand-3.1.0 \
		shlex-1.3.0 \
		similar-2.6.0 \
		snafu-0.8.5 \
		snafu-derive-0.8.5 \
		strsim-0.11.1 \
		strum-0.26.3 \
		strum_macros-0.26.4 \
		syn-1.0.109 \
		syn-2.0.79 \
		target-2.1.0 \
		tempfile-3.13.0 \
		temptree-0.2.0 \
		terminal_size-0.3.0 \
		thiserror-1.0.64 \
		thiserror-impl-1.0.64 \
		typed-arena-2.0.2 \
		typenum-1.17.0 \
		unicase-2.7.0 \
		unicode-ident-1.0.13 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.1.14 \
		unicode-width-0.2.0 \
		utf8parse-0.2.2 \
		uuid-1.10.0 \
		version_check-0.9.5 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.93 \
		wasm-bindgen-backend-0.2.93 \
		wasm-bindgen-macro-0.2.93 \
		wasm-bindgen-macro-support-0.2.93 \
		wasm-bindgen-shared-0.2.93 \
		which-6.0.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.52.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-sys-0.59.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		winsafe-0.0.19 \
		yansi-1.0.1 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		COMPLETIONS
OPTIONS_DEFAULT=	COMPLETIONS

COMPLETIONS_DESC=		Build and install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

post-install-COMPLETIONS-on:
.for _shell in bash fish zsh
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --completions ${_shell} \
		>${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

.include <bsd.port.mk>
