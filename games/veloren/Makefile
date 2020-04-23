# $FreeBSD$

PORTNAME=	veloren
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://veloren.net/icons/favicon/:icon \
		LOCAL/jbeich:assets
DISTFILES=	android-icon-192x192.png:icon \
		${PORTNAME}-assets-${DISTVERSIONFULL}.tar.xz:assets
EXTRACT_ONLY=	${DISTFILES:N*\:icon:C/:.*//}

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Multiplayer voxel RPG written in Rust

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libasound.so:audio/alsa-lib
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cargo gnome python:3.4+,build xorg
USE_GNOME=	gtk30
USE_XORG=	xcb
USE_GITHUB=	nodefault
GH_TUPLE=	Imberflur:guillotiere:42c298f5bcf0f95f1a004360d05e25ca3711e9ed:guillotiere \
		emoon:rust_minifb:bac71b297920c1f7ab5d6e384673d3ae5cc7d46d:minifb \
		bekker:msgbox-rs:68fe39a60019b38a1569ae4e9ed796a0f0542673:msgbox \
		wusyong:portpicker-rs:06b989ac271ada33f9d44e7bcfcb10d55ead0c43:portpicker \
		RustAudio:rodio:e5474a2ef15f2d0a3bae2538de159b6d3e5bdf79:rodio
USE_GITLAB=	yes
GL_COMMIT=	f97bf5b3ec18d7664b4e905a9de407a4cadfa3e1
GL_TUPLE=	veloren:conrod:d28fd18c3092d4c26cf6df11673da195b3bc01db:conrod_core \
		veloren:specs-idvs:111548cf44e9bb4c43feb12aa3fc253953ac6e4a:specsidvs \
		yusdacra:treeculler:6c0fdf1c1cbf00be22e37410985d6a3973cd9bed:treeculler
INSTALLS_ICONS=	yes
PLIST_FILES=	bin/${PORTNAME}-chat-cli \
		bin/${PORTNAME}-server-cli \
		bin/${PORTNAME}-voxygen \
		share/icons/hicolor/192x192/apps/${PORTNAME}.png
PORTDATA=	*

DESKTOP_ENTRIES="Veloren (client)" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME}-voxygen" \
		"Game;RolePlaying;" \
		""

CARGO_CRATES=	adler32-1.0.4 \
		ahash-0.2.18 \
		aho-corasick-0.7.6 \
		alsa-sys-0.1.2 \
		andrew-0.2.1 \
		android_glue-0.2.3 \
		anymap-0.12.1 \
		approx-0.1.1 \
		approx-0.3.2 \
		arr_macro-0.1.3 \
		arr_macro_impl-0.1.3 \
		arrayref-0.3.5 \
		arrayvec-0.4.12 \
		arrayvec-0.5.1 \
		ascii-0.8.7 \
		atk-sys-0.6.0 \
		atom-0.3.5 \
		atty-0.2.13 \
		autocfg-0.1.7 \
		backtrace-0.3.40 \
		backtrace-sys-0.1.32 \
		base64-0.9.3 \
		base64-0.10.1 \
		bincode-1.2.0 \
		bindgen-0.51.1 \
		bitflags-1.2.1 \
		bitvec-0.15.2 \
		blake2b_simd-0.5.9 \
		block-0.1.6 \
		brotli-sys-0.3.2 \
		brotli2-0.3.2 \
		bstr-0.2.8 \
		buf_redux-0.8.4 \
		byteorder-0.5.3 \
		byteorder-1.3.2 \
		c2-chacha-0.2.3 \
		c_vec-1.3.3 \
		cairo-rs-0.4.1 \
		cairo-sys-rs-0.6.0 \
		cast-0.2.3 \
		cc-1.0.47 \
		cexpr-0.3.6 \
		cfg-if-0.1.10 \
		cgl-0.2.3 \
		chashmap-2.2.2 \
		chrono-0.4.10 \
		chunked_transfer-0.3.1 \
		clang-sys-0.28.1 \
		clap-2.33.0 \
		claxon-0.4.2 \
		clipboard-win-2.2.0 \
		cloudabi-0.0.3 \
		cocoa-0.18.5 \
		cocoa-0.19.1 \
		color_quant-1.0.1 \
		colored-1.9.0 \
		const-random-0.1.6 \
		const-random-macro-0.1.6 \
		constant_time_eq-0.1.4 \
		copypasta-0.6.0 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		core-graphics-0.17.3 \
		coreaudio-rs-0.9.1 \
		coreaudio-sys-0.2.3 \
		cpal-0.10.0 \
		crc32fast-1.2.0 \
		criterion-0.3.0 \
		criterion-plot-0.4.0 \
		crossbeam-0.7.2 \
		crossbeam-channel-0.3.9 \
		crossbeam-channel-0.4.0 \
		crossbeam-deque-0.7.2 \
		crossbeam-epoch-0.7.2 \
		crossbeam-epoch-0.8.0 \
		crossbeam-queue-0.1.2 \
		crossbeam-queue-0.2.0 \
		crossbeam-utils-0.6.6 \
		crossbeam-utils-0.7.0 \
		csv-1.1.1 \
		csv-core-0.1.6 \
		daggy-0.5.0 \
		deflate-0.7.20 \
		derivative-1.0.3 \
		deunicode-1.0.0 \
		directories-2.0.2 \
		dirs-1.0.5 \
		dirs-sys-0.3.4 \
		dispatch-0.1.4 \
		dlib-0.4.1 \
		dot_vox-4.0.0 \
		downcast-rs-1.1.1 \
		draw_state-0.8.0 \
		either-1.5.3 \
		env_logger-0.6.2 \
		euc-0.3.0 \
		euclid-0.19.9 \
		euclid_macros-0.1.0 \
		failure-0.1.6 \
		failure_derive-0.1.6 \
		fern-0.5.9 \
		filetime-0.2.8 \
		find_folder-0.3.0 \
		fixedbitset-0.1.9 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		fsevent-2.0.1 \
		fsevent-sys-3.0.0 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		gdk-0.8.0 \
		gdk-pixbuf-0.4.0 \
		gdk-pixbuf-sys-0.6.0 \
		gdk-sys-0.6.0 \
		getrandom-0.1.13 \
		gfx-0.18.2 \
		gfx_core-0.9.2 \
		gfx_device_gl-0.16.2 \
		gfx_gl-0.6.0 \
		gfx_window_glutin-0.31.0 \
		gif-0.10.3 \
		gio-0.4.1 \
		gio-sys-0.6.0 \
		gl_generator-0.11.0 \
		gl_generator-0.13.1 \
		gleam-0.6.19 \
		glib-0.5.0 \
		glib-sys-0.6.0 \
		glob-0.3.0 \
		glsl-include-0.3.1 \
		glutin-0.21.1 \
		glutin_egl_sys-0.1.4 \
		glutin_emscripten_sys-0.1.0 \
		glutin_gles2_sys-0.1.3 \
		glutin_glx_sys-0.1.5 \
		glutin_wgl_sys-0.1.3 \
		gobject-sys-0.6.0 \
		gtk-0.4.1 \
		gtk-sys-0.6.0 \
		gzip-header-0.3.0 \
		hashbrown-0.6.3 \
		hermit-abi-0.1.3 \
		hibitset-0.6.2 \
		hound-3.4.0 \
		httparse-1.3.4 \
		humantime-1.3.0 \
		idna-0.1.5 \
		image-0.22.3 \
		indexmap-1.3.0 \
		inflate-0.4.5 \
		inotify-0.8.2 \
		inotify-sys-0.1.3 \
		instant-0.1.2 \
		iovec-0.1.4 \
		itertools-0.8.2 \
		itoa-0.4.4 \
		jpeg-decoder-0.1.16 \
		kernel32-sys-0.2.2 \
		khronos_api-3.1.0 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		lewton-0.9.4 \
		libc-0.2.65 \
		libloading-0.5.2 \
		line_drawing-0.7.0 \
		linked-hash-map-0.5.2 \
		lock_api-0.3.1 \
		log-0.3.9 \
		log-0.4.8 \
		lz4-compress-0.1.1 \
		lzw-0.10.0 \
		mach-0.2.3 \
		malloc_buf-0.0.6 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-2.2.1 \
		memmap-0.7.0 \
		memoffset-0.5.3 \
		mime-0.2.6 \
		mime_guess-1.8.7 \
		minimp3-0.3.3 \
		minimp3-sys-0.3.1 \
		mio-0.6.21 \
		mio-extras-2.0.5 \
		miow-0.2.1 \
		mopa-0.2.2 \
		multipart-0.15.4 \
		net2-0.2.33 \
		nix-0.14.1 \
		nodrop-0.1.14 \
		noise-0.6.0 \
		nom-4.2.3 \
		notify-5.0.0-pre.2 \
		num-0.1.42 \
		num-0.2.0 \
		num-bigint-0.2.3 \
		num-complex-0.2.3 \
		num-derive-0.2.5 \
		num-integer-0.1.41 \
		num-iter-0.1.39 \
		num-rational-0.2.2 \
		num-traits-0.1.43 \
		num-traits-0.2.10 \
		num_cpus-1.11.1 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		ogg-0.7.0 \
		orbclient-0.3.27 \
		ordered-float-1.0.2 \
		osmesa-sys-0.1.2 \
		owning_ref-0.3.3 \
		packed_simd-0.3.3 \
		pango-0.4.0 \
		pango-sys-0.6.0 \
		parking_lot-0.4.8 \
		parking_lot-0.9.0 \
		parking_lot_core-0.2.14 \
		parking_lot_core-0.6.2 \
		peeking_take_while-0.1.2 \
		percent-encoding-1.0.1 \
		percent-encoding-2.1.0 \
		petgraph-0.4.13 \
		phf-0.7.24 \
		phf_codegen-0.7.24 \
		phf_generator-0.7.24 \
		phf_shared-0.7.24 \
		piston-float-0.3.0 \
		piston-viewport-0.5.0 \
		pistoncore-input-0.24.0 \
		pkg-config-0.3.17 \
		png-0.15.1 \
		ppv-lite86-0.2.6 \
		pretty_env_logger-0.3.1 \
		proc-macro-hack-0.5.11 \
		proc-macro2-0.3.8 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.6 \
		prometheus-0.7.0 \
		prometheus-static-metric-0.2.0 \
		protobuf-2.8.1 \
		quick-error-1.2.2 \
		quote-0.5.2 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.4.6 \
		rand-0.5.6 \
		rand-0.6.5 \
		rand-0.7.2 \
		rand_chacha-0.1.1 \
		rand_chacha-0.2.1 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rand_core-0.5.1 \
		rand_hc-0.1.0 \
		rand_hc-0.2.0 \
		rand_isaac-0.1.1 \
		rand_jitter-0.1.4 \
		rand_os-0.1.3 \
		rand_os-0.2.2 \
		rand_pcg-0.1.2 \
		rand_pcg-0.2.1 \
		rand_xorshift-0.1.1 \
		rand_xoshiro-0.3.1 \
		raw-window-handle-0.3.1 \
		rayon-1.3.0 \
		rayon-core-1.7.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.1 \
		regex-1.3.1 \
		regex-automata-0.1.8 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		ron-0.5.1 \
		roots-0.0.5 \
		rouille-3.0.0 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		rustc-hash-1.0.1 \
		rustc_version-0.2.3 \
		rusttype-0.7.9 \
		rusttype-0.8.2 \
		ryu-1.0.2 \
		safemem-0.3.3 \
		same-file-1.0.5 \
		scan_fmt-0.2.4 \
		scoped_threadpool-0.1.9 \
		scopeguard-1.0.0 \
		sdl2-0.32.2 \
		sdl2-sys-0.32.6 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.102 \
		serde_derive-1.0.102 \
		serde_json-1.0.42 \
		sha1-0.6.0 \
		shared_library-0.1.9 \
		shlex-0.1.1 \
		shred-0.9.4 \
		shred-derive-0.6.1 \
		shrev-1.1.1 \
		siphasher-0.2.3 \
		slab-0.4.2 \
		slice-deque-0.2.4 \
		smallvec-0.6.13 \
		smallvec-1.0.0 \
		smithay-client-toolkit-0.4.6 \
		smithay-client-toolkit-0.6.4 \
		smithay-clipboard-0.3.6 \
		specs-0.15.1 \
		spin-0.5.2 \
		stable_deref_trait-1.1.1 \
		static_assertions-0.2.5 \
		stb_truetype-0.3.1 \
		stdweb-0.1.3 \
		sum_type-0.2.0 \
		svg_fmt-0.2.1 \
		syn-0.13.11 \
		syn-0.15.44 \
		syn-1.0.8 \
		synstructure-0.12.3 \
		tempdir-0.3.7 \
		term-0.5.2 \
		termcolor-1.0.5 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		threadpool-1.7.1 \
		tiff-0.3.1 \
		time-0.1.42 \
		tiny_http-0.6.2 \
		tinytemplate-1.0.2 \
		toml-0.5.5 \
		tuple_utils-0.3.0 \
		twoway-0.1.8 \
		unicase-1.4.2 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.11 \
		unicode-width-0.1.6 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		url-1.7.2 \
		uvth-3.1.1 \
		vek-0.9.11 \
		version_check-0.1.5 \
		void-1.0.2 \
		walkdir-2.2.9 \
		wasi-0.7.0 \
		wayland-client-0.21.13 \
		wayland-client-0.23.6 \
		wayland-commons-0.21.13 \
		wayland-commons-0.23.6 \
		wayland-protocols-0.21.13 \
		wayland-protocols-0.23.6 \
		wayland-scanner-0.21.13 \
		wayland-scanner-0.23.6 \
		wayland-sys-0.21.13 \
		wayland-sys-0.23.6 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2 \
		winit-0.19.5 \
		winres-0.1.11 \
		ws2_32-sys-0.2.1 \
		x11-clipboard-0.3.3 \
		x11-dl-2.18.4 \
		xcb-0.8.2 \
		xdg-2.2.0 \
		xml-rs-0.8.0
CARGO_USE_GITHUB=	yes
CARGO_USE_GITLAB=	yes
CARGO_GIT_SUBDIR=	conrod_core:conrod_core:conrod_core \
			conrod_core:conrod_winit:backends/conrod_winit
# https://gitlab.com/veloren/veloren/issues/264
CARGO_ENV=		RUSTC_BOOTSTRAP=1
# XXX https://github.com/rust-lang/cargo/issues/4101
CARGO_INSTALL_PATH=	chat-cli server-cli voxygen

post-extract:
# XXX https://gitlab.com/gitlab-org/gitlab/issues/15079
# Replace LFS placeholders with data from a LOCAL snapshot
	@${RM} -r ${WRKSRC}/assets
	@${MV} ${WRKDIR}/assets ${WRKSRC}

post-patch:
# .git/ directory is missing, so don't abort if git binary is also missing
	@${REINPLACE_CMD} -e 's/"git"/"${TRUE}"/' \
		${WRKSRC}/common/build.rs
# Extract (snapshot) version from the port instead of empty file
	@${REINPLACE_CMD} -e '/GIT_HASH/s/=.*/= "${DISTVERSIONFULL}";/' \
		-e "/GIT_DATE/s/=.*/= \"$$(date -r $$(${AWK} '/TIMESTAMP/ { print $$3 }' \
			${DISTINFO_FILE}) +'%Y-%m-%d-%H:%M')\";/" \
		${WRKSRC}/common/src/util/mod.rs
# Enable system assets
	@${REINPLACE_CMD} -e '/linux/d; s,/usr/share,${DATADIR:H},' \
		${WRKSRC}/common/src/assets/mod.rs
# lang/python3 cannot be used as a dependency
	@${REINPLACE_CMD} -e 's/"python3"/"${PYTHON_CMD:T}"/' \
		${WRKSRC}/cargo-crates/xcb-*/build.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	(cd ${WRKSRC} && ${COPYTREE_SHARE} assets ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/192x192/apps
	${INSTALL_DATA} ${DISTDIR}/android-icon-192x192.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/192x192/apps/${PORTNAME}.png

.include <bsd.port.mk>
