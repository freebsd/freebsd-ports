PORTNAME=	solanum
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.1
PORTREVISION=	3
CATEGORIES=	deskutils

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	e5c5d88f95b0.patch:-p1 # https://gitlab.gnome.org/World/Solanum/-/merge_requests/49

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Pomodoro timer for the GNOME desktop

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo gettext gnome gstreamer meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER=	bad good vorbis
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Solanum
GL_COMMIT=	3f84b1d0c46fe1a3daef2940b1d0747222023984
SHEBANG_FILES=	build-aux/meson/postinstall.py
MAKE_ENV=	${CARGO_ENV}
GLIB_SCHEMAS=	org.gnome.Solanum.gschema.xml

CARGO_CRATES=	aho-corasick-0.7.18 \
		anyhow-1.0.41 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		cairo-rs-0.14.7 \
		cairo-sys-rs-0.14.0 \
		cc-1.0.68 \
		cfg-expr-0.7.4 \
		cfg-expr-0.9.0 \
		cfg-if-1.0.0 \
		either-1.6.1 \
		field-offset-0.3.4 \
		futures-channel-0.3.15 \
		futures-core-0.3.15 \
		futures-executor-0.3.15 \
		futures-io-0.3.15 \
		futures-task-0.3.15 \
		futures-util-0.3.15 \
		gdk-pixbuf-0.14.0 \
		gdk-pixbuf-sys-0.14.0 \
		gdk4-0.3.0 \
		gdk4-sys-0.3.0 \
		gettext-rs-0.4.4 \
		gettext-sys-0.19.9 \
		gio-0.14.6 \
		gio-sys-0.14.0 \
		glib-0.14.5 \
		glib-macros-0.14.1 \
		glib-sys-0.14.0 \
		gobject-sys-0.14.0 \
		graphene-rs-0.14.0 \
		graphene-sys-0.14.0 \
		gsk4-0.3.0 \
		gsk4-sys-0.3.0 \
		gstreamer-0.17.4 \
		gstreamer-base-0.17.2 \
		gstreamer-base-sys-0.17.0 \
		gstreamer-player-0.17.0 \
		gstreamer-player-sys-0.17.0 \
		gstreamer-sys-0.17.3 \
		gstreamer-video-0.17.2 \
		gstreamer-video-sys-0.17.0 \
		gtk-macros-0.2.0 \
		gtk4-0.3.0 \
		gtk4-macros-0.3.0 \
		gtk4-sys-0.3.0 \
		heck-0.3.3 \
		itertools-0.10.1 \
		lazy_static-1.4.0 \
		libadwaita-0.1.0-alpha-6 \
		libadwaita-sys-0.1.0-alpha-6 \
		libc-0.2.97 \
		locale_config-0.2.3 \
		memchr-2.4.0 \
		memoffset-0.6.4 \
		muldiv-1.0.0 \
		num-integer-0.1.44 \
		num-rational-0.4.0 \
		num-traits-0.2.14 \
		once_cell-1.8.0 \
		pango-0.14.3 \
		pango-sys-0.14.0 \
		paste-1.0.5 \
		pest-2.1.3 \
		pin-project-lite-0.2.6 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		pretty-hex-0.2.1 \
		proc-macro-crate-1.0.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		regex-1.5.4 \
		regex-syntax-0.6.25 \
		rustc_version-0.3.3 \
		semver-0.11.0 \
		semver-parser-0.10.2 \
		serde-1.0.126 \
		slab-0.4.3 \
		smallvec-1.6.1 \
		strum-0.20.0 \
		strum_macros-0.20.1 \
		syn-1.0.73 \
		system-deps-3.1.1 \
		system-deps-4.0.0 \
		thiserror-1.0.25 \
		thiserror-impl-1.0.25 \
		toml-0.5.8 \
		ucd-trie-0.1.3 \
		unicode-segmentation-1.7.1 \
		unicode-xid-0.2.2 \
		version-compare-0.0.11 \
		version_check-0.9.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e '/cargo/s/ --/&verbose&verbose&/' \
		${WRKSRC}/build-aux/cargo.sh

.include <bsd.port.mk>
