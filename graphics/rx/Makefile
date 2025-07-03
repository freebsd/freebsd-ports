PORTNAME=	rx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.2
PORTREVISION=	37
CATEGORIES=	graphics
PKGNAMESUFFIX=	-editor

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Modern and minimalist pixel editor implemented in rust
WWW=		https://rx.cloudhead.io/ \
		https://github.com/cloudhead/rx

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON=	meowhash crate only supports x86_64, see https://github.com/bodil/meowhash-rs/issues/5

USES=		cargo xorg
USE_GITHUB=	yes
GH_ACCOUNT=	cloudhead
USE_XORG=	x11 xcursor xext xi xinerama xrandr

CARGO_CRATES=	adler32-1.0.4 \
		arrayref-0.3.6 \
		arrayvec-0.5.1 \
		autocfg-1.0.0 \
		base64-0.11.0 \
		bitflags-1.2.1 \
		blake2b_simd-0.5.10 \
		byteorder-1.3.4 \
		c2-chacha-0.2.3 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		cmake-0.1.42 \
		color_quant-1.0.1 \
		constant_time_eq-0.1.5 \
		crc32fast-1.2.0 \
		crossbeam-utils-0.7.2 \
		deflate-0.8.6 \
		digest-0.8.1 \
		directories-2.0.2 \
		dirs-sys-0.3.4 \
		flate2-1.0.14 \
		generic-array-0.12.3 \
		getrandom-0.1.14 \
		gif-0.10.3 \
		gl-0.14.0 \
		gl_generator-0.14.0 \
		glfw-0.41.0 \
		glfw-sys-3.3.2 \
		itoa-0.4.6 \
		khronos_api-3.1.0 \
		lazy_static-1.4.0 \
		libc-0.2.92 \
		log-0.4.14 \
		luminance-0.43.2 \
		luminance-derive-0.6.3 \
		luminance-gl-0.16.1 \
		lzw-0.10.0 \
		malloc_buf-0.0.6 \
		memoir-0.2.1 \
		mini-internal-0.1.13 \
		miniserde-0.1.13 \
		miniz_oxide-0.3.6 \
		nonempty-0.1.5 \
		num-integer-0.1.44 \
		num-traits-0.2.11 \
		objc-0.2.7 \
		pico-args-0.3.1 \
		png-0.16.6 \
		podio-0.1.6 \
		ppv-lite86-0.2.6 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		rand-0.7.3 \
		rand_chacha-0.2.1 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		raw-window-handle-0.3.3 \
		redox_syscall-0.1.56 \
		redox_users-0.3.4 \
		remove_dir_all-0.5.2 \
		rgx-0.8.1 \
		rust-argon2-0.7.0 \
		ryu-1.0.5 \
		seahash-4.0.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.114 \
		serde_derive-1.0.113 \
		snap-0.2.5 \
		syn-1.0.16 \
		tempfile-3.1.0 \
		time-0.1.44 \
		toml-0.5.6 \
		typenum-1.11.2 \
		unicode-xid-0.2.0 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xml-rs-0.8.0 \
		zip-0.5.5
PLIST_FILES=	bin/rx

LDFLAGS+=	-L${PREFIX}/lib

.include <bsd.port.mk>
