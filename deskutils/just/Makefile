PORTNAME=	just
DISTVERSION=	1.16.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Just a command runner: handy way to save/run project-specific commands
WWW=		https://just.systems/

LICENSE=	CC0-1.0
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	compilation fails: error[E0308]: mismatched types, see https://github.com/dotenv-rs/dotenv/issues/83

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	casey

CARGO_CRATES=	aho-corasick-1.1.2 \
		ansi_term-0.12.1 \
		atty-0.2.14 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		block-buffer-0.10.4 \
		bstr-0.2.17 \
		camino-1.1.6 \
		cfg-if-1.0.0 \
		clap-2.34.0 \
		cpufeatures-0.2.11 \
		cradle-0.2.2 \
		crypto-common-0.1.6 \
		ctrlc-3.4.1 \
		derivative-2.2.0 \
		diff-0.1.13 \
		digest-0.10.7 \
		doc-comment-0.3.3 \
		dotenvy-0.15.7 \
		edit-distance-2.1.0 \
		either-1.9.0 \
		env_logger-0.10.0 \
		errno-0.3.6 \
		executable-path-1.0.0 \
		fastrand-2.0.1 \
		generic-array-0.14.7 \
		getopts-0.2.21 \
		getrandom-0.2.11 \
		heck-0.3.3 \
		heck-0.4.1 \
		hermit-abi-0.1.19 \
		hermit-abi-0.3.3 \
		home-0.5.5 \
		humantime-2.1.0 \
		is-terminal-0.4.9 \
		itoa-1.0.9 \
		lazy_static-1.4.0 \
		lexiclean-0.0.1 \
		libc-0.2.150 \
		linked-hash-map-0.5.6 \
		linux-raw-sys-0.4.11 \
		log-0.4.20 \
		memchr-2.6.4 \
		nix-0.27.1 \
		num_cpus-1.16.0 \
		once_cell-1.18.0 \
		pretty_assertions-1.4.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.69 \
		pulldown-cmark-0.9.3 \
		pulldown-cmark-to-cmark-10.0.4 \
		quote-1.0.33 \
		redox_syscall-0.4.1 \
		regex-1.10.2 \
		regex-automata-0.1.10 \
		regex-automata-0.4.3 \
		regex-syntax-0.8.2 \
		rustix-0.38.21 \
		rustversion-1.0.14 \
		ryu-1.0.15 \
		semver-1.0.20 \
		serde-1.0.192 \
		serde_derive-1.0.192 \
		serde_json-1.0.108 \
		sha2-0.10.8 \
		similar-2.3.0 \
		snafu-0.7.5 \
		snafu-derive-0.7.5 \
		strsim-0.8.0 \
		structopt-0.3.26 \
		structopt-derive-0.4.18 \
		strum-0.25.0 \
		strum_macros-0.25.3 \
		syn-1.0.109 \
		syn-2.0.39 \
		target-2.0.0 \
		tempfile-3.8.1 \
		temptree-0.2.0 \
		term_size-0.3.2 \
		termcolor-1.3.0 \
		textwrap-0.11.0 \
		typed-arena-2.0.2 \
		typenum-1.17.0 \
		unicase-2.7.0 \
		unicode-ident-1.0.12 \
		unicode-segmentation-1.10.1 \
		unicode-width-0.1.11 \
		uuid-1.5.0 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		which-5.0.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-targets-0.48.5 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_msvc-0.48.5 \
		windows_i686_gnu-0.48.5 \
		windows_i686_msvc-0.48.5 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_msvc-0.48.5 \
		yaml-rust-0.4.5 \
		yansi-0.5.1

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		COMPLETIONS
OPTIONS_DEFAULT=	COMPLETIONS

COMPLETIONS_DESC=		Build and install bash, fish and zsh shell completions
COMPLETIONS_PLIST_FILES=	share/bash-completion/completions/${PORTNAME} \
				share/fish/vendor_completions.d/${PORTNAME}.fish \
				share/zsh/site-functions/_${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-COMPLETIONS-on:
.for _shell in bash fish zsh
	${STAGEDIR}${PREFIX}/bin/${PORTNAME} --completions ${_shell} \
		>${STAGEDIR}${PREFIX}/${COMPLETIONS_PLIST_FILES:M*${_shell}*}
.endfor

.include <bsd.port.mk>
