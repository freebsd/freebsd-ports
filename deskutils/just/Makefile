PORTNAME=	just
DISTVERSION=	1.43.1
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

CARGO_CRATES=	aho-corasick-1.1.4 \
		android_system_properties-0.1.5 \
		ansi_term-0.12.1 \
		anstream-0.6.21 \
		anstyle-1.0.13 \
		anstyle-parse-0.2.7 \
		anstyle-query-1.1.4 \
		anstyle-wincon-3.0.10 \
		arrayref-0.3.9 \
		arrayvec-0.7.6 \
		autocfg-1.5.0 \
		bitflags-2.10.0 \
		blake3-1.8.2 \
		block-buffer-0.10.4 \
		block2-0.6.2 \
		bstr-1.12.1 \
		bumpalo-3.19.0 \
		camino-1.2.1 \
		cc-1.2.45 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		chrono-0.4.42 \
		clap-4.5.51 \
		clap_builder-4.5.51 \
		clap_complete-4.5.48 \
		clap_derive-4.5.49 \
		clap_lex-0.7.6 \
		clap_mangen-0.2.31 \
		colorchoice-1.0.4 \
		constant_time_eq-0.3.1 \
		core-foundation-sys-0.8.7 \
		cpufeatures-0.2.17 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crypto-common-0.1.7 \
		ctrlc-3.5.1 \
		derive-where-1.6.0 \
		diff-0.1.13 \
		digest-0.10.7 \
		dirs-6.0.0 \
		dirs-sys-0.5.0 \
		dispatch2-0.3.0 \
		dotenvy-0.15.7 \
		edit-distance-2.2.2 \
		env_home-0.1.0 \
		errno-0.3.14 \
		executable-path-1.0.0 \
		fastrand-2.3.0 \
		find-msvc-tools-0.1.4 \
		generic-array-0.14.7 \
		getopts-0.2.24 \
		getrandom-0.2.16 \
		getrandom-0.3.4 \
		heck-0.5.0 \
		hermit-abi-0.5.2 \
		iana-time-zone-0.1.64 \
		iana-time-zone-haiku-0.1.2 \
		is_executable-1.0.5 \
		is_terminal_polyfill-1.70.2 \
		itoa-1.0.15 \
		js-sys-0.3.82 \
		lexiclean-0.0.1 \
		libc-0.2.177 \
		libredox-0.1.10 \
		linux-raw-sys-0.11.0 \
		log-0.4.28 \
		memchr-2.7.6 \
		memmap2-0.9.9 \
		nix-0.30.1 \
		num-traits-0.2.19 \
		num_cpus-1.17.0 \
		objc2-0.6.3 \
		objc2-encode-4.1.0 \
		once_cell-1.21.3 \
		once_cell_polyfill-1.70.2 \
		option-ext-0.2.0 \
		percent-encoding-2.3.2 \
		ppv-lite86-0.2.21 \
		pretty_assertions-1.4.1 \
		proc-macro2-1.0.103 \
		pulldown-cmark-0.9.6 \
		pulldown-cmark-to-cmark-10.0.4 \
		quote-1.0.42 \
		r-efi-5.3.0 \
		rand-0.9.2 \
		rand_chacha-0.9.0 \
		rand_core-0.9.3 \
		rayon-core-1.13.0 \
		redox_users-0.5.2 \
		regex-1.12.2 \
		regex-automata-0.4.13 \
		regex-syntax-0.8.8 \
		roff-0.2.2 \
		rustix-1.1.2 \
		rustversion-1.0.22 \
		ryu-1.0.20 \
		semver-1.0.27 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_json-1.0.145 \
		sha2-0.10.9 \
		shellexpand-3.1.1 \
		shlex-1.3.0 \
		similar-2.7.0 \
		snafu-0.8.9 \
		snafu-derive-0.8.9 \
		strsim-0.11.1 \
		strum-0.27.2 \
		strum_macros-0.27.2 \
		syn-2.0.110 \
		target-2.1.0 \
		tempfile-3.23.0 \
		temptree-0.2.0 \
		terminal_size-0.4.3 \
		thiserror-2.0.17 \
		thiserror-impl-2.0.17 \
		typed-arena-2.0.2 \
		typenum-1.19.0 \
		unicase-2.8.1 \
		unicode-ident-1.0.22 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.2.2 \
		utf8parse-0.2.2 \
		uuid-1.18.1 \
		version_check-0.9.5 \
		wasi-0.11.1+wasi-snapshot-preview1 \
		wasip2-1.0.1+wasi-0.2.4 \
		wasm-bindgen-0.2.105 \
		wasm-bindgen-macro-0.2.105 \
		wasm-bindgen-macro-support-0.2.105 \
		wasm-bindgen-shared-0.2.105 \
		which-8.0.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-core-0.62.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-result-0.4.1 \
		windows-strings-0.5.1 \
		windows-sys-0.60.2 \
		windows-sys-0.61.2 \
		windows-targets-0.53.5 \
		windows_aarch64_gnullvm-0.53.1 \
		windows_aarch64_msvc-0.53.1 \
		windows_i686_gnu-0.53.1 \
		windows_i686_gnullvm-0.53.1 \
		windows_i686_msvc-0.53.1 \
		windows_x86_64_gnu-0.53.1 \
		windows_x86_64_gnullvm-0.53.1 \
		windows_x86_64_msvc-0.53.1 \
		winsafe-0.0.19 \
		wit-bindgen-0.46.0 \
		yansi-1.0.1 \
		zerocopy-0.8.27 \
		zerocopy-derive-0.8.27
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
