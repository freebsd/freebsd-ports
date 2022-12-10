PORTNAME=	amberol
DISTVERSION=	0.9.2
CATEGORIES=	audio

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Plays music, and nothing else
WWW=		https://gitlab.gnome.org/World/amberol

LICENSE=	CC0-1.0 CC-BY-SA-3.0 GPLv3+
LICENSE_COMB=	multi
LICENSE_FILE_CC0-1.0=	${WRKSRC}/LICENSES/CC0-1.0.txt
LICENSE_FILE_CC-BY-SA-3.0=	${WRKSRC}/LICENSES/CC-BY-SA-3.0.txt
LICENSE_FILE_GPLv3+ =	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

BROKEN_i386=	gmp-mpfr-sys fails to build bundled libraries

LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libgraphene-1.0.so:graphics/graphene

USES=		cargo desktop-file-utils gettext gnome gstreamer meson pkgconfig
USE_GITLAB=	yes
USE_GNOME=	gdkpixbuf2 gtk40 libadwaita
USE_GSTREAMER=	bad good libav
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_COMMIT=	c23ec2f11fa441c402b80f7a1733ac9aea65c81d
MAKE_ENV=	${CARGO_ENV}
GLIB_SCHEMAS=	io.bassi.Amberol.gschema.xml

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-0.7.18 \
		anyhow-1.0.56 \
		array-init-2.0.0 \
		ashpd-0.3.2 \
		async-broadcast-0.4.0 \
		async-channel-1.6.1 \
		async-executor-1.4.1 \
		async-io-1.7.0 \
		async-lock-2.5.0 \
		async-recursion-0.3.2 \
		async-task-4.2.0 \
		async-trait-0.1.53 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		az-1.2.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		block-0.1.6 \
		block-buffer-0.10.2 \
		bytemuck-1.9.1 \
		byteorder-1.4.3 \
		cache-padded-1.2.0 \
		cairo-rs-0.15.6 \
		cairo-sys-rs-0.15.1 \
		cc-1.0.73 \
		cfg-expr-0.10.2 \
		cfg-if-1.0.0 \
		color-thief-0.2.1 \
		concurrent-queue-1.2.2 \
		cpufeatures-0.2.2 \
		crc32fast-1.3.2 \
		crypto-common-0.1.3 \
		dbus-0.6.5 \
		derivative-2.2.0 \
		digest-0.10.3 \
		easy-parallel-3.2.0 \
		either-1.6.1 \
		enumflags2-0.7.5 \
		enumflags2_derive-0.7.4 \
		env_logger-0.7.1 \
		event-listener-2.5.2 \
		fastrand-1.7.0 \
		field-offset-0.3.4 \
		flate2-1.0.24 \
		futures-0.3.21 \
		futures-channel-0.3.21 \
		futures-core-0.3.21 \
		futures-executor-0.3.21 \
		futures-io-0.3.21 \
		futures-lite-1.12.0 \
		futures-macro-0.3.21 \
		futures-sink-0.3.21 \
		futures-task-0.3.21 \
		futures-util-0.3.21 \
		fuzzy-matcher-0.3.7 \
		gdk-pixbuf-0.15.6 \
		gdk-pixbuf-sys-0.15.1 \
		gdk4-0.4.8 \
		gdk4-sys-0.4.8 \
		gdk4-wayland-0.4.7 \
		gdk4-wayland-sys-0.4.8 \
		gdk4-x11-0.4.2 \
		gdk4-x11-sys-0.4.2 \
		generic-array-0.14.5 \
		getrandom-0.2.6 \
		gettext-rs-0.7.0 \
		gettext-sys-0.21.2 \
		gio-0.15.7 \
		gio-sys-0.15.7 \
		glib-0.10.3 \
		glib-0.15.9 \
		glib-macros-0.10.1 \
		glib-macros-0.15.6 \
		glib-sys-0.10.1 \
		glib-sys-0.15.7 \
		gmp-mpfr-sys-1.4.8 \
		gobject-sys-0.10.0 \
		gobject-sys-0.15.9 \
		graphene-rs-0.15.1 \
		graphene-sys-0.15.1 \
		gsk4-0.4.8 \
		gsk4-sys-0.4.8 \
		gstreamer-0.18.6 \
		gstreamer-audio-0.18.7 \
		gstreamer-audio-sys-0.18.3 \
		gstreamer-base-0.18.0 \
		gstreamer-base-sys-0.18.0 \
		gstreamer-player-0.18.0 \
		gstreamer-player-sys-0.18.0 \
		gstreamer-sys-0.18.0 \
		gstreamer-video-0.18.5 \
		gstreamer-video-sys-0.18.3 \
		gtk-macros-0.3.0 \
		gtk4-0.4.8 \
		gtk4-macros-0.4.8 \
		gtk4-sys-0.4.8 \
		heck-0.3.3 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hex-0.4.3 \
		humantime-1.3.0 \
		instant-0.1.12 \
		itertools-0.9.0 \
		itoa-1.0.2 \
		lazy_static-1.4.0 \
		libadwaita-0.2.0-alpha.2 \
		libadwaita-sys-0.2.0-alpha.2 \
		libc-0.2.121 \
		libdbus-sys-0.2.2 \
		locale_config-0.3.0 \
		lock_api-0.4.7 \
		lofty-0.9.0 \
		lofty_attr-0.4.0 \
		log-0.4.17 \
		malloc_buf-0.0.6 \
		memchr-2.4.1 \
		memoffset-0.6.5 \
		miniz_oxide-0.5.3 \
		mpris-player-0.6.1 \
		muldiv-1.0.0 \
		nix-0.23.1 \
		num-0.4.0 \
		num-bigint-0.4.3 \
		num-complex-0.4.1 \
		num-integer-0.1.44 \
		num-iter-0.1.43 \
		num-rational-0.4.0 \
		num-traits-0.2.14 \
		objc-0.2.7 \
		objc-foundation-0.1.1 \
		objc_id-0.1.1 \
		ogg_pager-0.3.2 \
		once_cell-1.13.0 \
		option-operations-0.4.0 \
		ordered-stream-0.0.1 \
		pango-0.15.7 \
		pango-sys-0.15.1 \
		parking-2.0.0 \
		parking_lot-0.11.2 \
		parking_lot_core-0.8.5 \
		paste-1.0.7 \
		pest-2.1.3 \
		pin-project-lite-0.2.8 \
		pin-utils-0.1.0 \
		pkg-config-0.3.24 \
		polling-2.2.0 \
		ppv-lite86-0.2.16 \
		pretty-hex-0.2.1 \
		pretty_env_logger-0.4.0 \
		proc-macro-crate-0.1.5 \
		proc-macro-crate-1.1.3 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.43 \
		quick-error-1.2.3 \
		quick-xml-0.22.0 \
		quote-1.0.21 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		redox_syscall-0.2.13 \
		regex-1.5.5 \
		regex-syntax-0.6.25 \
		remove_dir_all-0.5.3 \
		rgb-0.8.32 \
		rgb_derivation-0.2.0 \
		rug-1.16.0 \
		rustc_version-0.3.3 \
		ryu-1.0.10 \
		scopeguard-1.1.0 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.136 \
		serde_derive-1.0.136 \
		serde_json-1.0.81 \
		serde_repr-0.1.8 \
		sha1-0.6.1 \
		sha1_smol-1.0.0 \
		sha2-0.10.2 \
		slab-0.4.5 \
		smallvec-1.8.0 \
		socket2-0.4.4 \
		srgb-0.3.0 \
		static_assertions-1.1.0 \
		strum-0.18.0 \
		strum_macros-0.18.0 \
		syn-1.0.99 \
		system-deps-1.3.2 \
		system-deps-6.0.2 \
		temp-dir-0.1.11 \
		tempfile-3.3.0 \
		termcolor-1.1.3 \
		thiserror-1.0.30 \
		thiserror-impl-1.0.30 \
		thread_local-1.1.4 \
		toml-0.5.8 \
		typenum-1.15.0 \
		ucd-trie-0.1.3 \
		uds_windows-1.0.2 \
		unicode-ident-1.0.3 \
		unicode-segmentation-1.9.0 \
		version-compare-0.0.10 \
		version-compare-0.1.0 \
		version_check-0.9.4 \
		waker-fn-1.1.0 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wepoll-ffi-0.1.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		zbus-2.2.0 \
		zbus_macros-2.2.0 \
		zbus_names-2.1.0 \
		zvariant-3.2.1 \
		zvariant_derive-3.2.1
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

post-patch:
# Allow running from background via xdg-desktop-portal
	@${REINPLACE_CMD} -e 's/linux/${OPSYS:tl}/' \
		${WRKSRC}/src/window.rs \
		${WRKSRC}/Cargo.toml
# Make each cargo subcommand very verbose
# Add explicit <triple> subdir for --target from USES=cargo
	@${REINPLACE_CMD} -e "/cargo_options =/s/ '--/&verbose', &verbose', &/" \
		-e "/cp/s,'src',& / '${CARGO_BUILD_TARGET}'," \
		${WRKSRC}/src/meson.build

.include <bsd.port.mk>
