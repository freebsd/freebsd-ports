PORTNAME=	frawk
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.7
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Efficient awk-like language
WWW=		https://github.com/ezrosent/frawk

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

BROKEN=		error[E0635]: unknown feature stdsimd, see https://github.com/ezrosent/frawk/issues/110

BUILD_DEPENDS=	gmake:devel/gmake \
		rust-nightly>0:lang/rust-nightly

USES=		cargo gnome llvm:min=12,max=12,lib localbase:ldflags
USE_GNOME=	libxml2

USE_GITHUB=	yes
GH_ACCOUNT=	ezrosent

MAKE_ENV=	LLVM_SYS_120_PREFIX=${LOCALBASE}/llvm12

CARGO_BUILDDEP=	no
CARGO_CRATES=	ahash-0.7.6 \
		aho-corasick-0.7.18 \
		anyhow-1.0.56 \
		arrayvec-0.7.2 \
		ascii-canvas-3.0.0 \
		assert_cmd-2.0.4 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		bit-set-0.5.2 \
		bit-vec-0.6.3 \
		bitflags-1.3.2 \
		bstr-0.2.17 \
		bumpalo-3.9.1 \
		byteorder-1.4.3 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		clap-3.1.8 \
		cranelift-0.91.0 \
		cranelift-bforest-0.91.0 \
		cranelift-codegen-0.91.0 \
		cranelift-codegen-meta-0.91.0 \
		cranelift-codegen-shared-0.91.0 \
		cranelift-egraph-0.91.0 \
		cranelift-entity-0.91.0 \
		cranelift-frontend-0.91.0 \
		cranelift-isle-0.91.0 \
		cranelift-jit-0.91.0 \
		cranelift-module-0.91.0 \
		cranelift-native-0.91.0 \
		crossbeam-0.8.1 \
		crossbeam-channel-0.5.4 \
		crossbeam-deque-0.8.1 \
		crossbeam-epoch-0.9.8 \
		crossbeam-queue-0.3.5 \
		crossbeam-utils-0.8.8 \
		crunchy-0.2.2 \
		diff-0.1.12 \
		difflib-0.4.0 \
		dirs-next-2.0.0 \
		dirs-sys-next-0.1.2 \
		doc-comment-0.3.3 \
		either-1.6.1 \
		ena-0.14.0 \
		fallible-iterator-0.2.0 \
		fast-float-0.2.0 \
		fastrand-1.7.0 \
		fixedbitset-0.2.0 \
		fixedbitset-0.4.1 \
		fnv-1.0.7 \
		fs_extra-1.2.0 \
		fxhash-0.2.1 \
		getrandom-0.2.6 \
		gimli-0.26.1 \
		globset-0.4.8 \
		grep-cli-0.1.6 \
		hashbrown-0.11.2 \
		hashbrown-0.12.3 \
		hermit-abi-0.1.19 \
		indexmap-1.9.2 \
		instant-0.1.12 \
		itertools-0.10.3 \
		itoa-1.0.1 \
		lalrpop-0.19.7 \
		lalrpop-util-0.19.7 \
		lazy_static-1.4.0 \
		libc-0.2.122 \
		llvm-sys-120.2.3 \
		lock_api-0.4.7 \
		log-0.4.16 \
		mach-0.3.2 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		new_debug_unreachable-1.0.4 \
		num_cpus-1.13.1 \
		once_cell-1.10.0 \
		os_str_bytes-6.0.0 \
		parking_lot-0.12.0 \
		parking_lot_core-0.9.2 \
		paste-1.0.7 \
		pest-2.1.3 \
		petgraph-0.5.1 \
		petgraph-0.6.0 \
		phf_shared-0.10.0 \
		pico-args-0.4.2 \
		ppv-lite86-0.2.16 \
		precomputed-hash-0.1.1 \
		predicates-2.1.1 \
		predicates-core-1.0.3 \
		predicates-tree-1.0.5 \
		proc-macro2-1.0.37 \
		quote-1.0.17 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		redox_syscall-0.2.13 \
		redox_users-0.4.3 \
		regalloc2-0.5.1 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		region-2.2.0 \
		remove_dir_all-0.5.3 \
		rustversion-1.0.6 \
		ryu-1.0.9 \
		same-file-1.0.6 \
		scopeguard-1.1.0 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		siphasher-0.3.10 \
		slice-group-by-0.3.0 \
		smallvec-1.8.0 \
		stable_deref_trait-1.2.0 \
		string_cache-0.8.4 \
		strsim-0.10.0 \
		syn-1.0.91 \
		target-lexicon-0.12.3 \
		tempfile-3.3.0 \
		term-0.7.0 \
		termcolor-1.1.3 \
		termtree-0.2.4 \
		textwrap-0.15.0 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		tikv-jemalloc-sys-0.4.3+5.2.1-patched.2 \
		tikv-jemallocator-0.4.3 \
		tiny-keccak-2.0.2 \
		ucd-trie-0.1.3 \
		unicode-xid-0.2.2 \
		version_check-0.9.4 \
		wait-timeout-0.2.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasmtime-jit-icache-coherence-3.0.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.34.0 \
		windows-sys-0.42.0 \
		windows_aarch64_gnullvm-0.42.0 \
		windows_aarch64_msvc-0.34.0 \
		windows_aarch64_msvc-0.42.0 \
		windows_i686_gnu-0.34.0 \
		windows_i686_gnu-0.42.0 \
		windows_i686_msvc-0.34.0 \
		windows_i686_msvc-0.42.0 \
		windows_x86_64_gnu-0.34.0 \
		windows_x86_64_gnu-0.42.0 \
		windows_x86_64_gnullvm-0.42.0 \
		windows_x86_64_msvc-0.34.0 \
		windows_x86_64_msvc-0.42.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
