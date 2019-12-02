# $FreeBSD$

PORTNAME=	veloren
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
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

USES=		cargo gnome
USE_GNOME=	gtk30
USE_GITHUB=	nodefault
GH_TUPLE=	Songtronix:rust-discord-rpc:5823404967954992c0ee48c731f12ab2ca3aaa1d:discordrpcsdk \
		emoon:rust_minifb:0e3bf4a7e23d099fce60bcf7855a245543f809a1:minifb \
		bekker:msgbox-rs:d3e12e1cbfcd280bb4de5ad8032bded37d8e573f:msgbox \
		wusyong:portpicker-rs:06b989ac271ada33f9d44e7bcfcb10d55ead0c43:portpicker \
		RustAudio:rodio:e5474a2ef15f2d0a3bae2538de159b6d3e5bdf79:rodio
USE_GITLAB=	yes
GL_COMMIT=	ee5142c6d10031cbf8cfa071ee0bbaa0aa45a93e
GL_TUPLE=	veloren:conrod:d603363488870eae9df91ba45ba795509c8a6ab4:conrod_core \
		veloren:specs-idvs:4ce792042f951a29874954582234836c0eccaed6:specsidvs \
		veloren:sphynx:ac4adf54d181339a789907acd27f61fe81daa455:sphynx
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
		ahash-0.2.13 \
		aho-corasick-0.6.10 \
		aho-corasick-0.7.6 \
		alsa-sys-0.1.2 \
		andrew-0.2.1 \
		android_glue-0.2.3 \
		ansi_term-0.11.0 \
		anymap-0.12.1 \
		approx-0.1.1 \
		approx-0.3.2 \
		arr_macro-0.1.2 \
		arr_macro_impl-0.1.2 \
		arrayref-0.3.5 \
		arrayvec-0.4.11 \
		arrayvec-0.5.0 \
		ascii-0.8.7 \
		aster-0.41.0 \
		atk-sys-0.6.0 \
		atom-0.3.5 \
		atty-0.2.13 \
		autocfg-0.1.6 \
		backtrace-0.3.38 \
		backtrace-sys-0.1.31 \
		base64-0.10.1 \
		base64-0.9.3 \
		bincode-1.2.0 \
		bindgen-0.26.3 \
		bindgen-0.51.1 \
		bitflags-0.8.2 \
		bitflags-0.9.1 \
		bitflags-1.2.0 \
		blake2b_simd-0.5.8 \
		block-0.1.6 \
		brotli-sys-0.3.2 \
		brotli2-0.3.2 \
		bstr-0.2.8 \
		buf_redux-0.8.4 \
		byteorder-0.5.3 \
		byteorder-1.3.2 \
		c2-chacha-0.2.2 \
		c_vec-1.3.3 \
		cairo-rs-0.4.1 \
		cairo-sys-rs-0.6.0 \
		cast-0.2.2 \
		cc-1.0.45 \
		cexpr-0.2.3 \
		cexpr-0.3.5 \
		cfg-if-0.1.10 \
		cgl-0.2.3 \
		chashmap-2.2.2 \
		chrono-0.4.9 \
		chunked_transfer-0.3.1 \
		clang-sys-0.19.0 \
		clang-sys-0.28.1 \
		clap-2.33.0 \
		claxon-0.4.2 \
		cloudabi-0.0.3 \
		cmake-0.1.42 \
		cocoa-0.14.0 \
		cocoa-0.18.4 \
		color_quant-1.0.1 \
		const-random-0.1.6 \
		const-random-macro-0.1.6 \
		constant_time_eq-0.1.4 \
		core-foundation-0.5.1 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.5.1 \
		core-foundation-sys-0.6.2 \
		core-graphics-0.13.0 \
		core-graphics-0.17.3 \
		coreaudio-rs-0.9.1 \
		coreaudio-sys-0.2.3 \
		cpal-0.10.0 \
		crc32fast-1.2.0 \
		criterion-0.3.0 \
		criterion-plot-0.4.0 \
		crossbeam-0.4.1 \
		crossbeam-0.7.2 \
		crossbeam-channel-0.2.6 \
		crossbeam-channel-0.3.9 \
		crossbeam-deque-0.5.2 \
		crossbeam-deque-0.7.1 \
		crossbeam-epoch-0.5.2 \
		crossbeam-epoch-0.6.1 \
		crossbeam-epoch-0.7.2 \
		crossbeam-queue-0.1.2 \
		crossbeam-utils-0.5.0 \
		crossbeam-utils-0.6.6 \
		csv-1.1.1 \
		csv-core-0.1.6 \
		daggy-0.5.0 \
		deflate-0.7.20 \
		derivative-1.0.3 \
		directories-2.0.2 \
		dirs-1.0.5 \
		dirs-sys-0.3.4 \
		dlib-0.4.1 \
		dot_vox-4.0.0 \
		downcast-rs-1.0.4 \
		draw_state-0.8.0 \
		either-1.5.3 \
		enum_primitive-0.1.1 \
		env_logger-0.4.3 \
		env_logger-0.6.2 \
		euc-0.3.0 \
		euclid-0.19.9 \
		euclid_macros-0.1.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		filetime-0.2.7 \
		find_folder-0.3.0 \
		fixedbitset-0.1.9 \
		fnv-1.0.6 \
		foreign-types-0.3.2 \
		foreign-types-shared-0.1.1 \
		frustum_query-0.1.2 \
		fsevent-0.4.0 \
		fsevent-sys-2.0.1 \
		fuchsia-cprng-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		fxhash-0.2.1 \
		gdk-0.8.0 \
		gdk-pixbuf-0.4.0 \
		gdk-pixbuf-sys-0.6.0 \
		gdk-sys-0.6.0 \
		getrandom-0.1.12 \
		gfx-0.18.1 \
		gfx_core-0.9.1 \
		gfx_device_gl-0.16.2 \
		gfx_gl-0.6.0 \
		gfx_window_glutin-0.31.0 \
		gif-0.10.3 \
		gif-0.9.2 \
		gio-0.4.1 \
		gio-sys-0.6.0 \
		gl_generator-0.11.0 \
		gl_generator-0.13.1 \
		gleam-0.6.19 \
		glib-0.5.0 \
		glib-sys-0.6.0 \
		glob-0.2.11 \
		glob-0.3.0 \
		glsl-include-0.3.1 \
		glutin-0.21.1 \
		glutin_egl_sys-0.1.3 \
		glutin_emscripten_sys-0.1.0 \
		glutin_gles2_sys-0.1.3 \
		glutin_glx_sys-0.1.5 \
		glutin_wgl_sys-0.1.3 \
		gobject-sys-0.6.0 \
		gtk-0.4.1 \
		gtk-sys-0.6.0 \
		guillotiere-0.4.2 \
		gzip-header-0.3.0 \
		hashbrown-0.5.0 \
		hashbrown-0.6.0 \
		heaptrack-0.3.0 \
		hibitset-0.5.4 \
		hound-3.4.0 \
		httparse-1.3.4 \
		humantime-1.3.0 \
		idna-0.1.5 \
		image-0.18.0 \
		image-0.22.2 \
		inflate-0.3.4 \
		inflate-0.4.5 \
		inotify-0.7.0 \
		inotify-sys-0.1.3 \
		instant-0.1.1 \
		iovec-0.1.2 \
		itertools-0.8.0 \
		itoa-0.4.4 \
		jpeg-decoder-0.1.16 \
		kernel32-sys-0.2.2 \
		khronos_api-3.1.0 \
		lazy_static-0.2.11 \
		lazy_static-1.4.0 \
		lazycell-1.2.1 \
		lewton-0.9.4 \
		libc-0.2.62 \
		libloading-0.4.3 \
		libloading-0.5.2 \
		line_drawing-0.7.0 \
		linked-hash-map-0.5.2 \
		lock_api-0.1.5 \
		lock_api-0.3.1 \
		log-0.3.9 \
		log-0.4.8 \
		lz4-compress-0.1.1 \
		lzw-0.10.0 \
		mach-0.2.3 \
		malloc_buf-0.0.6 \
		matches-0.1.8 \
		maybe-uninit-2.0.0 \
		memchr-1.0.2 \
		memchr-2.2.1 \
		memmap-0.7.0 \
		memoffset-0.2.1 \
		memoffset-0.5.1 \
		mime-0.2.6 \
		mime_guess-1.8.7 \
		minimp3-0.3.3 \
		minimp3-sys-0.3.1 \
		mio-0.6.19 \
		mio-extras-2.0.5 \
		miow-0.2.1 \
		mopa-0.2.2 \
		multipart-0.15.4 \
		net2-0.2.33 \
		nix-0.14.1 \
		nodrop-0.1.13 \
		noise-0.5.1 \
		nom-3.2.1 \
		nom-4.2.3 \
		nonzero_signed-1.0.3 \
		notify-5.0.0-pre.1 \
		num-0.1.42 \
		num-0.2.0 \
		num-bigint-0.2.3 \
		num-complex-0.2.3 \
		num-derive-0.2.5 \
		num-integer-0.1.41 \
		num-iter-0.1.39 \
		num-rational-0.1.42 \
		num-rational-0.2.2 \
		num-traits-0.1.43 \
		num-traits-0.2.8 \
		num_cpus-1.10.1 \
		objc-0.2.6 \
		ogg-0.7.0 \
		orbclient-0.3.27 \
		ordered-float-1.0.2 \
		osmesa-sys-0.1.2 \
		owning_ref-0.3.3 \
		owning_ref-0.4.0 \
		pango-0.4.0 \
		pango-sys-0.6.0 \
		parking_lot-0.4.8 \
		parking_lot-0.6.4 \
		parking_lot-0.9.0 \
		parking_lot_core-0.2.14 \
		parking_lot_core-0.3.1 \
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
		pkg-config-0.3.16 \
		png-0.11.0 \
		png-0.15.0 \
		ppv-lite86-0.2.5 \
		pretty_env_logger-0.3.1 \
		proc-macro-hack-0.5.9 \
		proc-macro2-0.3.8 \
		proc-macro2-0.4.30 \
		proc-macro2-1.0.4 \
		prometheus-0.7.0 \
		prometheus-static-metric-0.2.0 \
		protobuf-2.8.1 \
		quasi-0.32.0 \
		quasi_codegen-0.32.0 \
		quick-error-1.2.2 \
		quote-0.5.2 \
		quote-0.6.13 \
		quote-1.0.2 \
		rand-0.3.23 \
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
		rand_xorshift-0.1.1 \
		rand_xoshiro-0.3.1 \
		rayon-1.2.0 \
		rayon-core-1.6.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		redox_users-0.3.1 \
		regex-0.2.11 \
		regex-1.3.1 \
		regex-automata-0.1.8 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.12 \
		remove_dir_all-0.5.2 \
		ron-0.5.1 \
		rouille-3.0.0 \
		rust-argon2-0.5.1 \
		rustc-demangle-0.1.16 \
		rustc-hash-1.0.1 \
		rustc-serialize-0.3.24 \
		rustc_version-0.2.3 \
		rusttype-0.7.9 \
		rusttype-0.8.1 \
		ryu-1.0.0 \
		safemem-0.3.2 \
		same-file-1.0.5 \
		scan_fmt-0.2.4 \
		scoped_threadpool-0.1.9 \
		scopeguard-0.3.3 \
		scopeguard-1.0.0 \
		sdl2-0.32.2 \
		sdl2-sys-0.32.6 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.101 \
		serde_derive-1.0.101 \
		serde_json-1.0.40 \
		sha1-0.6.0 \
		shared_library-0.1.9 \
		shlex-0.1.1 \
		shred-0.7.2 \
		shred-derive-0.5.1 \
		shrev-1.1.1 \
		simplelog-0.6.0 \
		siphasher-0.2.3 \
		slab-0.4.2 \
		slice-deque-0.2.4 \
		smallvec-0.6.10 \
		smithay-client-toolkit-0.4.6 \
		specs-0.14.3 \
		spin-0.5.2 \
		stable_deref_trait-1.1.1 \
		static_assertions-0.2.5 \
		stb_truetype-0.3.0 \
		stdweb-0.1.3 \
		strsim-0.8.0 \
		sum_type-0.2.0 \
		svg_fmt-0.2.1 \
		syn-0.13.11 \
		syn-0.15.44 \
		syn-1.0.5 \
		synstructure-0.10.2 \
		syntex-0.58.1 \
		syntex_errors-0.58.1 \
		syntex_pos-0.58.1 \
		syntex_syntax-0.58.1 \
		tempdir-0.3.7 \
		term-0.4.6 \
		term-0.5.2 \
		termcolor-1.0.5 \
		textwrap-0.11.0 \
		thread_local-0.3.6 \
		threadpool-1.7.1 \
		tiff-0.3.1 \
		time-0.1.42 \
		tiny_http-0.6.2 \
		tinytemplate-1.0.2 \
		toml-0.5.3 \
		tuple_utils-0.2.0 \
		twoway-0.1.8 \
		ucd-util-0.1.5 \
		unicase-1.4.2 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-width-0.1.6 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		unicode-xid-0.2.0 \
		url-1.7.2 \
		user32-sys-0.2.0 \
		utf8-ranges-1.0.4 \
		uvth-3.1.1 \
		vec_map-0.8.1 \
		vek-0.9.9 \
		version_check-0.1.5 \
		void-1.0.2 \
		walkdir-2.2.9 \
		wasi-0.7.0 \
		wayland-client-0.21.13 \
		wayland-commons-0.21.13 \
		wayland-protocols-0.21.13 \
		wayland-scanner-0.21.13 \
		wayland-sys-0.21.13 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.2 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-1.0.2 \
		winit-0.19.3 \
		winres-0.1.11 \
		ws2_32-sys-0.2.1 \
		x11-dl-2.18.4 \
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
		${WRKSRC}/common/src/util/mod.rs
# Enable system assets
	@${REINPLACE_CMD} -e '/linux/d; s,/usr/share,${DATADIR:H},' \
		${WRKSRC}/common/src/assets/mod.rs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	(cd ${WRKSRC} && ${COPYTREE_SHARE} assets ${STAGEDIR}${DATADIR})
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/192x192/apps
	${INSTALL_DATA} ${DISTDIR}/android-icon-192x192.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/192x192/apps/${PORTNAME}.png

.include <bsd.port.mk>
