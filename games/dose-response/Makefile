# $FreeBSD$

PORTNAME=	dose-response
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.0
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Open-world roguelike game where you play an addict

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING.txt

LIB_DEPENDS+=	libSDL2.so:devel/sdl20

USES=		cargo gnome
USE_GITHUB=	yes
GH_ACCOUNT=	tryjumping
GH_TAGNAME=	179c326

CARGO_FEATURES+=	prod sdl2/use-pkgconfig

CARGO_CRATES=	adler32-1.0.3 \
		aho-corasick-0.7.6 \
		andrew-0.2.1 \
		android_glue-0.2.3 \
		ansi_term-0.11.0 \
		approx-0.3.0 \
		arrayvec-0.4.7 \
		ascii-0.9.1 \
		atty-0.2.11 \
		backtrace-0.3.11 \
		backtrace-sys-0.1.28 \
		bincode-1.0.1 \
		bitflags-1.0.4 \
		block-0.1.6 \
		byteorder-1.2.7 \
		cc-1.0.25 \
		cfg-if-0.1.6 \
		cgl-0.2.3 \
		chrono-0.4.9 \
		clap-2.32.0 \
		cloudabi-0.0.3 \
		cmake-0.1.35 \
		cocoa-0.18.4 \
		color_quant-1.0.1 \
		combine-3.8.1 \
		core-foundation-0.6.3 \
		core-foundation-sys-0.6.2 \
		core-graphics-0.17.3 \
		crc32fast-1.2.0 \
		crossbeam-deque-0.2.0 \
		crossbeam-epoch-0.3.1 \
		crossbeam-utils-0.2.2 \
		deflate-0.7.19 \
		derivative-1.0.2 \
		dlib-0.4.1 \
		downcast-rs-1.0.3 \
		either-1.5.0 \
		encoding_rs-0.8.20 \
		error-chain-0.10.0 \
		filetime-0.2.7 \
		flate2-1.0.12 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gif-0.10.1 \
		gl-0.10.0 \
		gl_generator-0.9.0 \
		gl_generator-0.10.0 \
		gl_generator-0.11.0 \
		gleam-0.6.7 \
		glutin-0.21.0 \
		glutin_egl_sys-0.1.3 \
		glutin_emscripten_sys-0.1.0 \
		glutin_gles2_sys-0.1.3 \
		glutin_glx_sys-0.1.5 \
		glutin_wgl_sys-0.1.3 \
		image-0.20.1 \
		inflate-0.4.3 \
		itoa-0.4.3 \
		jpeg-decoder-0.1.15 \
		khronos_api-2.2.0 \
		khronos_api-3.1.0 \
		lazy_static-1.3.0 \
		libc-0.2.65 \
		libloading-0.5.0 \
		line_drawing-0.7.0 \
		linked-hash-map-0.5.2 \
		lock_api-0.1.5 \
		lock_api-0.3.1 \
		log-0.3.9 \
		log-0.4.6 \
		log-panics-2.0.0 \
		lzw-0.10.0 \
		malloc_buf-0.0.6 \
		memchr-2.2.1 \
		memmap-0.7.0 \
		memoffset-0.2.1 \
		metadeps-1.1.2 \
		miniz_oxide-0.3.3 \
		nix-0.11.0 \
		nix-0.13.0 \
		nodrop-0.1.13 \
		num-0.1.42 \
		num-derive-0.2.3 \
		num-integer-0.1.39 \
		num-iter-0.1.37 \
		num-rational-0.2.1 \
		num-traits-0.2.6 \
		num_cpus-1.8.0 \
		objc-0.2.6 \
		oorandom-11.0.1 \
		ordered-float-1.0.1 \
		osmesa-sys-0.1.2 \
		owning_ref-0.4.0 \
		parking_lot-0.7.1 \
		parking_lot-0.9.0 \
		parking_lot_core-0.4.0 \
		parking_lot_core-0.6.2 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.14 \
		png-0.12.0 \
		proc-macro2-0.4.24 \
		quote-0.6.10 \
		rand-0.6.0 \
		rand_chacha-0.1.0 \
		rand_core-0.3.0 \
		rand_hc-0.1.0 \
		rand_isaac-0.1.0 \
		rand_pcg-0.1.1 \
		rand_xorshift-0.1.0 \
		raw-window-handle-0.3.1 \
		rayon-1.0.3 \
		rayon-core-1.4.1 \
		redox_syscall-0.1.42 \
		redox_termios-0.1.1 \
		regex-1.3.1 \
		regex-syntax-0.6.12 \
		rustc-demangle-0.1.13 \
		rustc_version-0.2.3 \
		rusttype-0.7.3 \
		ryu-0.2.7 \
		same-file-1.0.4 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		scopeguard-1.0.0 \
		sdl2-0.32.2 \
		sdl2-sys-0.32.6 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.80 \
		serde_derive-1.0.80 \
		serde_json-1.0.33 \
		shared_library-0.1.9 \
		simplelog-0.5.3 \
		smallvec-0.6.6 \
		smithay-client-toolkit-0.4.5 \
		stable_deref_trait-1.1.1 \
		stb_truetype-0.2.4 \
		strsim-0.7.0 \
		syn-0.15.21 \
		tar-0.4.26 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		thread_local-0.3.6 \
		tiff-0.2.1 \
		time-0.1.40 \
		toml-0.2.1 \
		toml-0.4.10 \
		toml_edit-0.1.5 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		unidiff-0.3.1 \
		unreachable-1.0.0 \
		vec_map-0.8.1 \
		void-1.0.2 \
		walkdir-2.2.7 \
		wayland-client-0.21.4 \
		wayland-commons-0.21.4 \
		wayland-protocols-0.21.4 \
		wayland-scanner-0.21.4 \
		wayland-sys-0.21.4 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.1 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winit-0.19.4 \
		winres-0.1.8 \
		x11-dl-2.18.3 \
		xattr-0.2.2 \
		xdg-2.2.0 \
		xml-rs-0.7.0 \
		xml-rs-0.8.0 \
		zmq-0.8.2 \
		zmq-sys-0.8.2

PLIST_FILES=	bin/${PORTNAME}
.for size in 16 32 48 64 256
PLIST_FILES+=	share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor

PORTDOCS=	CHANGELOG.md DEVELOPER-NOTES.md README.md
INSTALLS_ICONS=	yes
DESKTOP_ENTRIES=	"Dose Response" \
			"${COMMENT}" \
			"${PORTNAME}" \
			"${PORTNAME}" \
			"Games;" \
			false

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
.for size in 16 32 48 64 256
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}x${size}/apps
	${INSTALL_DATA} ${WRKSRC}/assets/icon_${size}x${size}.png \
		${STAGEDIR}${LOCALBASE}/share/icons/hicolor/${size}x${size}/apps/${PORTNAME}.png
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
