PORTNAME=	wgpu-native
DISTVERSIONPREFIX=	v
DISTVERSION=	29.0.1.1
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Native WebGPU implementation based on wgpu-core
WWW=		https://github.com/gfx-rs/wgpu-native

LICENSE=	APACHE20 MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE.APACHE
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE.MIT

USES=		cargo llvm:build
USE_GITHUB=	yes
USE_LDCONFIG=	yes
GH_ACCOUNT=	gfx-rs
GH_TUPLE=	webgpu-native:webgpu-headers:673658bc2bd70ec39fc55ebe6bb0173cf6d0a603:headers/ffi/webgpu-headers

CARGO_CRATES=	aho-corasick-1.1.4 \
		allocator-api2-0.2.21 \
		android_system_properties-0.1.5 \
		arrayvec-0.7.7 \
		ash-0.38.0+1.3.281 \
		autocfg-1.5.1 \
		bindgen-0.72.1 \
		bit-set-0.9.1 \
		bit-vec-0.9.1 \
		bitflags-2.13.0 \
		block2-0.6.2 \
		bumpalo-3.20.3 \
		bytemuck-1.25.0 \
		bytemuck_derive-1.10.2 \
		cexpr-0.6.0 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		clang-sys-1.8.1 \
		codespan-reporting-0.13.1 \
		crunchy-0.2.4 \
		dispatch2-0.3.1 \
		dlib-0.5.3 \
		document-features-0.2.12 \
		either-1.16.0 \
		equivalent-1.0.2 \
		fixedbitset-0.5.7 \
		foldhash-0.1.5 \
		foldhash-0.2.0 \
		futures-core-0.3.32 \
		futures-task-0.3.32 \
		futures-util-0.3.32 \
		gl_generator-0.14.0 \
		glob-0.3.3 \
		glow-0.17.0 \
		glutin_wgl_sys-0.6.1 \
		gpu-allocator-0.28.0 \
		gpu-descriptor-0.3.2 \
		gpu-descriptor-types-0.2.0 \
		half-2.7.1 \
		hashbrown-0.15.5 \
		hashbrown-0.16.1 \
		hashbrown-0.17.1 \
		hexf-parse-0.2.1 \
		indexmap-2.14.0 \
		itertools-0.13.0 \
		jni-sys-0.3.1 \
		jni-sys-0.4.1 \
		jni-sys-macros-0.4.1 \
		js-sys-0.3.102 \
		khronos-egl-6.0.0 \
		khronos_api-3.1.0 \
		libc-0.2.186 \
		libloading-0.8.9 \
		libm-0.2.16 \
		litrs-1.0.0 \
		lock_api-0.4.14 \
		log-0.4.33 \
		macro_rules_attribute-0.2.2 \
		macro_rules_attribute-proc_macro-0.2.2 \
		memchr-2.8.2 \
		minimal-lexical-0.2.1 \
		naga-29.0.3 \
		ndk-sys-0.6.0+11769913 \
		nom-7.1.3 \
		num-traits-0.2.19 \
		objc2-0.6.4 \
		objc2-core-foundation-0.3.2 \
		objc2-encode-4.1.0 \
		objc2-foundation-0.3.2 \
		objc2-metal-0.3.2 \
		objc2-quartz-core-0.3.2 \
		once_cell-1.21.4 \
		ordered-float-5.3.0 \
		parking_lot-0.12.5 \
		parking_lot_core-0.9.12 \
		paste-1.0.15 \
		petgraph-0.8.3 \
		pin-project-lite-0.2.17 \
		pkg-config-0.3.33 \
		pp-rs-0.2.1 \
		presser-0.3.1 \
		prettyplease-0.2.37 \
		proc-macro2-1.0.106 \
		profiling-1.0.18 \
		quote-1.0.45 \
		range-alloc-0.1.5 \
		raw-window-handle-0.6.2 \
		raw-window-metal-1.1.0 \
		redox_syscall-0.5.18 \
		regex-1.12.4 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.11 \
		renderdoc-sys-1.1.0 \
		rustc-hash-1.1.0 \
		rustc-hash-2.1.2 \
		rustversion-1.0.22 \
		scopeguard-1.2.0 \
		serde-1.0.228 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		shlex-1.3.0 \
		slab-0.4.12 \
		slotmap-1.1.1 \
		smallvec-1.15.2 \
		spirv-0.4.0+sdk-1.4.341.0 \
		syn-2.0.118 \
		thiserror-2.0.18 \
		thiserror-impl-2.0.18 \
		unicode-ident-1.0.24 \
		unicode-width-0.2.2 \
		unicode-xid-0.2.6 \
		version_check-0.9.5 \
		wasm-bindgen-0.2.125 \
		wasm-bindgen-macro-0.2.125 \
		wasm-bindgen-macro-support-0.2.125 \
		wasm-bindgen-shared-0.2.125 \
		wayland-sys-0.31.11 \
		web-sys-0.3.102 \
		wgpu-core-29.0.3 \
		wgpu-core-deps-apple-29.0.3 \
		wgpu-core-deps-emscripten-29.0.3 \
		wgpu-core-deps-windows-linux-android-29.0.3 \
		wgpu-hal-29.0.3 \
		wgpu-naga-bridge-29.0.3 \
		wgpu-types-29.0.3 \
		windows-0.62.2 \
		windows-collections-0.3.2 \
		windows-core-0.62.2 \
		windows-future-0.3.2 \
		windows-implement-0.60.2 \
		windows-interface-0.59.3 \
		windows-link-0.2.1 \
		windows-numerics-0.3.1 \
		windows-result-0.4.1 \
		windows-strings-0.5.1 \
		windows-threading-0.2.1 \
		xml-rs-0.8.28 \
		zerocopy-0.8.52 \
		zerocopy-derive-0.8.52

CARGO_ENV=	WGPU_NATIVE_VERSION=${DISTVERSION}

PLIST_FILES=	include/wgpu-native/webgpu.h \
		include/wgpu-native/wgpu.h \
		lib/libwgpu_native.so

do-install:
	${INSTALL_LIB} ${CARGO_TARGET_DIR}/*/libwgpu_native.so ${STAGEDIR}${PREFIX}/lib/
	${MKDIR} ${STAGEDIR}${PREFIX}/include/wgpu-native
	${INSTALL_DATA} ${WRKSRC}/ffi/wgpu.h ${WRKSRC}/ffi/webgpu-headers/webgpu.h \
		${STAGEDIR}${PREFIX}/include/wgpu-native/

.include <bsd.port.mk>
