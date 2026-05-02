PORTNAME=	electrs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.1
PORTREVISION=	4
CATEGORIES=	finance net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reimplementation of Electrum Server, a Bitcoin protocol server
WWW=		https://github.com/romanz/electrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	link fails: error: undefined symbol: _Unwind_SjLj_Register, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=283841

LIB_DEPENDS=	librocksdb.so:databases/rocksdb \
		libzstd.so:archivers/zstd

USES=		cargo llvm

USE_GITHUB=	yes
GH_ACCOUNT=	romanz

CARGO_CRATES=	aho-corasick-1.1.3 \
		anyhow-1.0.98 \
		arrayvec-0.7.6 \
		ascii-1.1.0 \
		autocfg-1.4.0 \
		base58ck-0.1.0 \
		base64-0.13.1 \
		bech32-0.11.0 \
		bindgen-0.69.5 \
		bitcoin-0.32.8 \
		bitcoin-internals-0.3.0 \
		bitcoin-io-0.1.3 \
		bitcoin-test-data-0.2.0 \
		bitcoin-units-0.1.2 \
		bitcoin_hashes-0.14.0 \
		bitcoin_slices-0.10.0 \
		bitcoincore-rpc-0.19.0 \
		bitcoincore-rpc-json-0.19.0 \
		bitflags-2.9.1 \
		block-buffer-0.10.4 \
		block2-0.6.2 \
		bzip2-sys-0.1.13+1.0.8 \
		cargo_toml-0.14.1 \
		cc-1.2.23 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		cfg_aliases-0.2.1 \
		chunked_transfer-1.5.0 \
		clang-sys-1.8.1 \
		configure_me-0.4.0 \
		configure_me_codegen-0.4.8 \
		cpufeatures-0.2.17 \
		crossbeam-channel-0.5.15 \
		crossbeam-deque-0.8.6 \
		crossbeam-epoch-0.9.18 \
		crossbeam-utils-0.8.21 \
		crypto-common-0.1.6 \
		ctrlc-3.5.1 \
		digest-0.10.7 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		dispatch2-0.3.0 \
		either-1.15.0 \
		env_logger-0.10.2 \
		errno-0.3.12 \
		fastrand-2.3.0 \
		fmt2io-1.0.0 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		getrandom-0.2.16 \
		getrandom-0.3.3 \
		glob-0.3.2 \
		hermit-abi-0.5.1 \
		hex-0.4.3 \
		hex-conservative-0.2.2 \
		hex_lit-0.1.1 \
		httpdate-1.0.3 \
		humantime-2.2.0 \
		is-terminal-0.4.16 \
		itertools-0.12.1 \
		itoa-1.0.15 \
		jobserver-0.1.33 \
		jsonrpc-0.18.0 \
		lazy_static-1.5.0 \
		lazycell-1.3.0 \
		libc-0.2.178 \
		libredox-0.1.3 \
		libz-sys-1.1.22 \
		linux-raw-sys-0.4.15 \
		linux-raw-sys-0.11.0 \
		lock_api-0.4.12 \
		log-0.4.29 \
		memchr-2.7.4 \
		minimal-lexical-0.2.1 \
		minreq-2.13.4 \
		nix-0.30.1 \
		nom-7.1.3 \
		objc2-0.6.3 \
		objc2-encode-4.1.0 \
		once_cell-1.21.3 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		parse_arg-0.1.6 \
		parse_arg-1.0.1 \
		pkg-config-0.3.32 \
		ppv-lite86-0.2.21 \
		proc-macro2-1.0.95 \
		procfs-0.17.0 \
		procfs-core-0.17.0 \
		prometheus-0.14.0 \
		protobuf-3.7.2 \
		protobuf-support-3.7.2 \
		quote-1.0.40 \
		r-efi-5.2.0 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rayon-1.11.0 \
		rayon-core-1.13.0 \
		redox_syscall-0.5.12 \
		redox_users-0.4.6 \
		regex-1.11.1 \
		regex-automata-0.4.9 \
		regex-syntax-0.8.5 \
		rust-librocksdb-sys-0.32.0+9.10.0 \
		rust-rocksdb-0.36.0 \
		rustc-hash-1.1.0 \
		rustix-0.38.44 \
		rustix-1.1.3 \
		scopeguard-1.2.0 \
		secp256k1-0.29.1 \
		secp256k1-sys-0.10.1 \
		serde-1.0.223 \
		serde_core-1.0.223 \
		serde_derive-1.0.223 \
		serde_json-1.0.149 \
		sha2-0.10.9 \
		shlex-1.3.0 \
		signal-hook-0.4.3 \
		signal-hook-registry-1.4.5 \
		smallvec-1.15.0 \
		syn-2.0.101 \
		tempfile-3.24.0 \
		termcolor-1.4.1 \
		thiserror-1.0.69 \
		thiserror-2.0.16 \
		thiserror-impl-1.0.69 \
		thiserror-impl-2.0.16 \
		tiny_http-0.12.0 \
		toml-0.5.11 \
		typenum-1.18.0 \
		unicode-ident-1.0.18 \
		unicode-segmentation-1.12.0 \
		vcpkg-0.2.15 \
		version_check-0.9.5 \
		void-1.0.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasi-0.14.2+wasi-0.2.4 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.9 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-link-0.2.0 \
		windows-sys-0.59.0 \
		windows-sys-0.61.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		wit-bindgen-rt-0.39.0 \
		zerocopy-0.8.25 \
		zerocopy-derive-0.8.25 \
		zmij-1.0.2 \
		zstd-sys-2.0.13+zstd.1.5.6

MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
