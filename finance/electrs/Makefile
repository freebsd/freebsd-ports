PORTNAME=	electrs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.10
CATEGORIES=	finance net-p2p

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Reimplementation of Electrum Server, a Bitcoin protocol server
WWW=		https://github.com/romanz/electrs

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv7=	link fails: error: undefined symbol: _Unwind_SjLj_Register, see https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=283841

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cargo llvm

USE_GITHUB=	yes
GH_ACCOUNT=	romanz

CARGO_CRATES=	aho-corasick-1.1.2 \
		anyhow-1.0.80 \
		arrayvec-0.7.4 \
		ascii-1.1.0 \
		autocfg-1.1.0 \
		base58ck-0.1.0 \
		base64-0.13.1 \
		bech32-0.11.0 \
		bindgen-0.63.0 \
		bitcoin-0.32.6 \
		bitcoin-internals-0.3.0 \
		bitcoin-io-0.1.2 \
		bitcoin-test-data-0.2.0 \
		bitcoin-units-0.1.1 \
		bitcoin_hashes-0.14.0 \
		bitcoin_slices-0.10.0 \
		bitcoincore-rpc-0.19.0 \
		bitcoincore-rpc-json-0.19.0 \
		bitflags-1.3.2 \
		bitflags-2.4.1 \
		block-buffer-0.10.4 \
		bzip2-sys-0.1.11+1.0.8 \
		cargo_toml-0.14.1 \
		cc-1.0.83 \
		cexpr-0.6.0 \
		cfg-if-1.0.0 \
		chunked_transfer-1.5.0 \
		clang-sys-1.6.1 \
		configure_me-0.4.0 \
		configure_me_codegen-0.4.8 \
		cpufeatures-0.2.11 \
		crossbeam-channel-0.5.15 \
		crossbeam-deque-0.8.4 \
		crossbeam-epoch-0.9.16 \
		crossbeam-utils-0.8.18 \
		crypto-common-0.1.6 \
		ctrlc-3.4.2 \
		digest-0.10.7 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		either-1.9.0 \
		electrs-librocksdb-sys-0.9.0-e3+7.8.3 \
		electrs-rocksdb-0.19.0-e3 \
		env_logger-0.10.2 \
		errno-0.3.10 \
		fastrand-2.1.1 \
		fmt2io-1.0.0 \
		fnv-1.0.7 \
		generic-array-0.14.7 \
		getrandom-0.2.11 \
		getrandom-0.3.1 \
		glob-0.3.1 \
		hermit-abi-0.3.3 \
		hex-0.4.3 \
		hex-conservative-0.2.0 \
		hex_lit-0.1.1 \
		httpdate-1.0.3 \
		humantime-2.1.0 \
		is-terminal-0.4.9 \
		itoa-1.0.10 \
		jobserver-0.1.26 \
		jsonrpc-0.18.0 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.171 \
		libloading-0.7.4 \
		libredox-0.0.1 \
		libz-sys-1.1.12 \
		linux-raw-sys-0.4.14 \
		linux-raw-sys-0.9.3 \
		lock_api-0.4.11 \
		log-0.4.27 \
		memchr-2.6.4 \
		memoffset-0.9.0 \
		minimal-lexical-0.2.1 \
		minreq-2.11.2 \
		nix-0.27.1 \
		nom-7.1.3 \
		once_cell-1.19.0 \
		parking_lot-0.12.1 \
		parking_lot_core-0.9.9 \
		parse_arg-0.1.4 \
		peeking_take_while-0.1.2 \
		pkg-config-0.3.28 \
		ppv-lite86-0.2.17 \
		proc-macro2-1.0.71 \
		procfs-0.16.0 \
		procfs-core-0.16.0 \
		prometheus-0.13.4 \
		protobuf-2.28.0 \
		quote-1.0.33 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		rayon-1.10.0 \
		rayon-core-1.12.1 \
		redox_syscall-0.4.1 \
		redox_users-0.4.4 \
		regex-1.9.6 \
		regex-automata-0.3.9 \
		regex-syntax-0.7.5 \
		rustc-hash-1.1.0 \
		rustix-0.38.40 \
		rustix-1.0.2 \
		ryu-1.0.16 \
		scopeguard-1.2.0 \
		secp256k1-0.29.0 \
		secp256k1-sys-0.10.0 \
		serde-1.0.171 \
		serde_derive-1.0.171 \
		serde_json-1.0.109 \
		sha2-0.10.8 \
		shlex-1.3.0 \
		signal-hook-0.3.18 \
		signal-hook-registry-1.4.1 \
		smallvec-1.13.1 \
		syn-1.0.109 \
		syn-2.0.42 \
		tempfile-3.20.0 \
		termcolor-1.4.1 \
		thiserror-1.0.55 \
		thiserror-impl-1.0.55 \
		tiny_http-0.12.0 \
		toml-0.5.11 \
		typenum-1.17.0 \
		unicode-ident-1.0.12 \
		unicode-segmentation-1.10.1 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		void-1.0.2 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		wasi-0.13.3+wasi-0.2.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.6 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
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
		wit-bindgen-rt-0.33.0 \
		zstd-sys-2.0.8+zstd.1.5.5

MAKE_ENV=	LIBCLANG_PATH=${LLVM_PREFIX}/lib

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
