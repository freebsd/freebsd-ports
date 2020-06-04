# $FreeBSD$

PORTNAME=	parinfer-rust
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.3
PORTREVISION=	3
CATEGORIES=	editors

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Infer parentheses for Clojure, Lisp, and Scheme

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	llvm${LLVM_DEFAULT}>0:devel/llvm${LLVM_DEFAULT}

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	eraserhd
USE_LDCONFIG=	yes

CARGO_CRATES=	aho-corasick-0.7.3 \
		ansi_term-0.11.0 \
		atty-0.2.11 \
		autocfg-0.1.4 \
		backtrace-0.3.30 \
		backtrace-sys-0.1.28 \
		base-x-0.2.5 \
		bindgen-0.48.1 \
		bitflags-1.1.0 \
		bumpalo-2.4.3 \
		byteorder-1.3.2 \
		cc-1.0.37 \
		cexpr-0.3.5 \
		cfg-if-0.1.9 \
		clang-sys-0.26.4 \
		clap-2.33.0 \
		ctor-0.1.9 \
		darling-0.9.0 \
		darling_core-0.9.0 \
		darling_macro-0.9.0 \
		discard-1.0.4 \
		emacs-0.11.0 \
		emacs-macros-0.11.0 \
		emacs_module-0.10.0 \
		env_logger-0.6.1 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fnv-1.0.6 \
		getopts-0.2.19 \
		glob-0.2.11 \
		hashbrown-0.1.8 \
		humantime-1.2.0 \
		ident_case-1.0.1 \
		itoa-0.4.4 \
		lazy_static-1.3.0 \
		libc-0.2.58 \
		libloading-0.5.1 \
		log-0.4.6 \
		memchr-2.2.0 \
		nom-4.2.3 \
		numtoa-0.1.0 \
		peeking_take_while-0.1.2 \
		proc-macro2-0.4.30 \
		quick-error-1.2.2 \
		quote-0.6.13 \
		redox_syscall-0.1.54 \
		redox_termios-0.1.1 \
		regex-1.1.7 \
		regex-syntax-0.6.7 \
		rustc-demangle-0.1.15 \
		rustc_version-0.2.3 \
		ryu-0.2.8 \
		scopeguard-0.3.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.92 \
		serde_derive-1.0.92 \
		serde_json-1.0.39 \
		sha1-0.6.0 \
		stdweb-0.4.17 \
		stdweb-derive-0.5.1 \
		stdweb-internal-macros-0.2.7 \
		stdweb-internal-runtime-0.1.4 \
		strsim-0.7.0 \
		strsim-0.8.0 \
		syn-0.15.42 \
		synstructure-0.10.2 \
		termcolor-1.0.5 \
		termion-1.5.2 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		ucd-util-0.1.3 \
		unicode-segmentation-1.3.0 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		utf8-ranges-1.0.3 \
		vec_map-0.8.1 \
		version_check-0.1.5 \
		wasm-bindgen-0.2.45 \
		wasm-bindgen-backend-0.2.45 \
		wasm-bindgen-macro-0.2.45 \
		wasm-bindgen-macro-support-0.2.45 \
		wasm-bindgen-shared-0.2.45 \
		which-2.0.1 \
		winapi-0.3.7 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.1

PLIST_FILES=	bin/parinfer-rust \
		lib/libparinfer_rust.so \
		share/kak/rc/extra/parinfer.kak \
		share/vim/vimfiles/doc/parinfer.txt \
		share/vim/vimfiles/plugin/parinfer.vim

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/parinfer-rust
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
