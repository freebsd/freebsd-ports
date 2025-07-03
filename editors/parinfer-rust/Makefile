PORTNAME=	parinfer-rust
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3.20220110
PORTREVISION=	32
CATEGORIES=	editors

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Infer parentheses for Clojure, Lisp, and Scheme
WWW=		https://github.com/eraserhd/parinfer-rust

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BROKEN_i386=	error: casting references to a bigger memory layout than the backing allocation is undefined behavior, even if the reference is unused

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eraserhd
GH_TAGNAME=	211f72e3
USE_LDCONFIG=	yes

CARGO_CRATES=	aho-corasick-0.7.15 \
		ansi_term-0.11.0 \
		anyhow-1.0.38 \
		atty-0.2.14 \
		base-x-0.2.8 \
		bindgen-0.56.0 \
		bitflags-1.2.1 \
		bumpalo-3.6.1 \
		cexpr-0.4.0 \
		cfg-if-1.0.0 \
		clang-sys-1.1.1 \
		clap-2.33.3 \
		ctor-0.1.19 \
		darling-0.10.2 \
		darling_core-0.10.2 \
		darling_macro-0.10.2 \
		discard-1.0.4 \
		emacs-0.16.2 \
		emacs-macros-0.15.1 \
		emacs_module-0.16.2 \
		env_logger-0.8.3 \
		fnv-1.0.7 \
		getopts-0.2.21 \
		glob-0.3.0 \
		hermit-abi-0.1.18 \
		humantime-2.1.0 \
		ident_case-1.0.1 \
		itoa-0.4.7 \
		lazy_static-1.4.0 \
		lazycell-1.3.0 \
		libc-0.2.87 \
		libloading-0.7.0 \
		log-0.4.14 \
		memchr-2.3.4 \
		nom-5.1.2 \
		once_cell-1.7.2 \
		peeking_take_while-0.1.2 \
		proc-macro2-1.0.24 \
		quote-1.0.9 \
		regex-1.4.3 \
		regex-syntax-0.6.22 \
		rustc-hash-1.1.0 \
		rustc_version-0.2.3 \
		ryu-1.0.5 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.123 \
		serde_derive-1.0.123 \
		serde_json-1.0.64 \
		sha1-0.6.0 \
		shlex-0.1.1 \
		stdweb-0.4.20 \
		stdweb-derive-0.5.3 \
		stdweb-internal-macros-0.2.9 \
		stdweb-internal-runtime-0.1.5 \
		strsim-0.8.0 \
		strsim-0.9.3 \
		syn-1.0.60 \
		termcolor-1.1.2 \
		textwrap-0.11.0 \
		thiserror-1.0.24 \
		thiserror-impl-1.0.24 \
		thread_local-1.1.3 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		vec_map-0.8.2 \
		version_check-0.9.2 \
		wasm-bindgen-0.2.71 \
		wasm-bindgen-backend-0.2.71 \
		wasm-bindgen-macro-0.2.71 \
		wasm-bindgen-macro-support-0.2.71 \
		wasm-bindgen-shared-0.2.71 \
		which-3.1.1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_FEATURES=	emacs

PLIST_FILES=	bin/parinfer-rust \
		lib/libparinfer_rust.so \
		share/kak/rc/extra/parinfer.kak \
		share/vim/vimfiles/doc/parinfer.txt \
		share/vim/vimfiles/plugin/parinfer.vim

post-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/libparinfer_rust.so \
		${STAGEDIR}${PREFIX}/lib
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/kak/rc/extra \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/doc \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/plugin
	${INSTALL_DATA} ${WRKSRC}/rc/parinfer.kak \
		${STAGEDIR}${PREFIX}/share/kak/rc/extra
	${INSTALL_DATA} ${WRKSRC}/doc/parinfer.txt \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/doc
	${INSTALL_DATA} ${WRKSRC}/plugin/parinfer.vim \
		${STAGEDIR}${PREFIX}/share/vim/vimfiles/plugin

.include <bsd.port.mk>
