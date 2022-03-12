PORTNAME=	fishfight
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2
CATEGORIES=	games

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Tactical 2D shooter in fishy pixels style

LICENSE=	CC-BY-NC-4.0 MIT
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/licenses/LICENSE-MIT

LIB_DEPENDS=	libasound.so:audio/alsa-lib \
		libudev.so:devel/libudev-devd
RUN_DEPENDS=	${LOCALBASE}/lib/alsa-lib/libasound_module_pcm_oss.so:audio/alsa-plugins

USES=		cargo gl localbase:ldflags xorg
USE_GITHUB=	yes
USE_GL=		gl
USE_XORG=	x11 xi
GH_PROJECT=	FishFight
PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

CARGO_CRATES=	adler32-1.2.0 \
		ahash-0.4.7 \
		ahash-0.7.6 \
		async-trait-0.1.52 \
		audir-sles-0.1.0 \
		audrey-0.3.0 \
		autocfg-1.1.0 \
		base-x-0.2.8 \
		bitflags-1.3.2 \
		bumpalo-3.9.1 \
		bytemuck-1.7.3 \
		byteorder-1.4.3 \
		cc-1.0.73 \
		cfg-if-1.0.0 \
		color_quant-1.1.0 \
		core-foundation-0.6.4 \
		core-foundation-sys-0.6.2 \
		crc32fast-1.3.2 \
		dasp_frame-0.11.0 \
		dasp_sample-0.11.0 \
		deflate-0.8.6 \
		discard-1.0.4 \
		ff-particles-0.1.2 \
		fnv-1.0.7 \
		fontdue-0.5.2 \
		getrandom-0.2.4 \
		gilrs-0.8.2 \
		gilrs-core-0.3.2 \
		glam-0.14.0 \
		hashbrown-0.9.1 \
		hashbrown-0.12.0 \
		hecs-0.7.6 \
		hound-3.4.0 \
		image-0.23.14 \
		io-kit-sys-0.1.0 \
		itoa-1.0.1 \
		js-sys-0.3.56 \
		lazy_static-1.4.0 \
		lewton-0.9.4 \
		libc-0.2.118 \
		libudev-sys-0.1.4 \
		log-0.4.14 \
		mach-0.2.3 \
		macroquad-0.3.13 \
		macroquad-platformer-0.1.2 \
		macroquad_macro-0.1.7 \
		maybe-uninit-2.0.0 \
		memoffset-0.6.5 \
		miniquad-0.3.0-alpha.42 \
		miniz_oxide-0.3.7 \
		ndk-sys-0.2.2 \
		nix-0.23.1 \
		num-integer-0.1.44 \
		num-iter-0.1.42 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		ogg-0.7.1 \
		once_cell-1.9.0 \
		pkg-config-0.3.24 \
		png-0.16.8 \
		proc-macro2-1.0.36 \
		quad-alsa-sys-0.3.2 \
		quad-rand-0.2.1 \
		quad-snd-0.2.3 \
		quote-1.0.15 \
		rustc_version-0.2.3 \
		rusty-xinput-1.2.0 \
		ryu-1.0.9 \
		sapp-android-0.1.14 \
		sapp-darwin-0.1.6 \
		sapp-dummy-0.1.5 \
		sapp-ios-0.1.2 \
		sapp-linux-0.1.13 \
		sapp-wasm-0.1.26 \
		sapp-windows-0.2.19 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.79 \
		sha1-0.6.1 \
		sha1_smol-1.0.0 \
		smallvec-0.6.14 \
		spin-0.9.2 \
		stdweb-0.4.20 \
		stdweb-derive-0.5.3 \
		stdweb-internal-macros-0.2.9 \
		stdweb-internal-runtime-0.1.5 \
		syn-1.0.86 \
		toml-0.5.8 \
		ttf-parser-0.12.3 \
		unicode-xid-0.2.2 \
		uuid-0.8.2 \
		vec_map-0.8.2 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasm-bindgen-0.2.79 \
		wasm-bindgen-backend-0.2.79 \
		wasm-bindgen-macro-0.2.79 \
		wasm-bindgen-macro-support-0.2.79 \
		wasm-bindgen-shared-0.2.79 \
		web-sys-0.3.56 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		fishsticks@git+https://github.com/fishfight/fishsticks\#95b45b717e427fb5fa1671f3bdf686d7270ad8a1

post-patch:
# Search assets under PREFIX instead of current directory
	@${REINPLACE_CMD} '/_dir/s,"\.,"${DATADIR},' ${WRKSRC}/src/main.rs

post-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "assets mods" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
