PORTNAME=	sigi
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.0
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	hiljusti@so.dang.cool
COMMENT=	Organizing tool for terminal lovers who hate organizing

LICENSE=	GPLv2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	hiljusti

CARGO_CRATES=	atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		cc-1.0.73 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-3.1.6 \
		clap_derive-3.1.4 \
		clearscreen-1.0.9 \
		clipboard-win-4.4.1 \
		dirs-2.0.2 \
		dirs-next-2.0.0 \
		dirs-sys-0.3.7 \
		dirs-sys-next-0.1.2 \
		either-1.6.1 \
		endian-type-0.1.2 \
		errno-0.2.8 \
		errno-dragonfly-0.1.2 \
		error-code-2.3.1 \
		fd-lock-3.0.5 \
		fnv-1.0.7 \
		getrandom-0.1.16 \
		getrandom-0.2.6 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.18 \
		indexmap-1.8.0 \
		io-lifetimes-0.6.1 \
		itoa-0.4.7 \
		json-0.12.4 \
		lazy_static-1.4.0 \
		libc-0.2.124 \
		linux-raw-sys-0.0.42 \
		log-0.4.16 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		nibble_vec-0.1.0 \
		nix-0.22.3 \
		nix-0.23.1 \
		nom-5.1.2 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		os_str_bytes-6.0.0 \
		phf-0.8.0 \
		phf_codegen-0.8.0 \
		phf_generator-0.8.0 \
		phf_shared-0.8.0 \
		ppv-lite86-0.2.16 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		pure-rust-locales-0.5.6 \
		quote-1.0.9 \
		radix_trie-0.2.1 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		rand_pcg-0.2.1 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		rustix-0.34.4 \
		rustyline-9.1.2 \
		ryu-1.0.5 \
		scopeguard-1.1.0 \
		serde-1.0.123 \
		serde_derive-1.0.123 \
		serde_json-1.0.64 \
		siphasher-0.3.10 \
		smallvec-1.8.0 \
		str-buf-1.0.5 \
		strsim-0.10.0 \
		syn-1.0.86 \
		termcolor-1.1.2 \
		terminfo-0.7.3 \
		textwrap-0.15.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		time-0.1.44 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.1 \
		utf8parse-0.2.0 \
		version_check-0.9.4 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		which-4.2.5 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.30.0 \
		windows_aarch64_msvc-0.30.0 \
		windows_i686_gnu-0.30.0 \
		windows_i686_msvc-0.30.0 \
		windows_x86_64_gnu-0.30.0 \
		windows_x86_64_msvc-0.30.0
CARGO_BUILD_ARGS=	--all

PLIST_FILES=	bin/sigi \
		man/man1/sigi.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/

.include <bsd.port.mk>
