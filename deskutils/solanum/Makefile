PORTNAME=	solanum
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
PORTREVISION=	6
CATEGORIES=	deskutils

PATCH_SITES=	${GL_SITE}/${GL_ACCOUNT}/${GL_PROJECT}/-/commit/
PATCHFILES+=	e5c5d88f95b0.patch:-p1 # https://gitlab.gnome.org/World/Solanum/-/merge_requests/49

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Pomodoro timer for the GNOME desktop

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo gettext gnome meson pkgconfig python:build shebangfix
USE_GITLAB=	yes
USE_GNOME=	gtk40 libadwaita
USE_GSTREAMER1=	bad good vorbis
GL_SITE=	https://gitlab.gnome.org
GL_ACCOUNT=	World
GL_PROJECT=	Solanum
GL_COMMIT=	3e69272fb31bf18a7aa74ece9d904d445c458274
SHEBANG_FILES=	build-aux/meson/postinstall.py
MAKE_ENV=	${CARGO_ENV}
GLIB_SCHEMAS=	org.gnome.Solanum.gschema.xml

CARGO_CRATES=	aho-corasick-0.7.15 \
		anyhow-1.0.35 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		cc-1.0.66 \
		cfg-if-1.0.0 \
		cmake-0.1.45 \
		either-1.6.1 \
		field-offset-0.3.2 \
		freetype-0.7.0 \
		freetype-sys-0.13.1 \
		futures-channel-0.3.8 \
		futures-core-0.3.8 \
		futures-executor-0.3.8 \
		futures-io-0.3.8 \
		futures-task-0.3.8 \
		futures-util-0.3.8 \
		gettext-rs-0.4.4 \
		gettext-sys-0.19.9 \
		gtk-macros-0.2.0 \
		heck-0.3.1 \
		itertools-0.9.0 \
		itertools-0.10.0 \
		lazy_static-1.4.0 \
		libc-0.2.81 \
		locale_config-0.2.3 \
		memchr-2.3.4 \
		memoffset-0.5.6 \
		muldiv-1.0.0 \
		num-integer-0.1.44 \
		num-rational-0.3.2 \
		num-traits-0.2.14 \
		once_cell-1.5.2 \
		paste-1.0.4 \
		pin-project-1.0.2 \
		pin-project-internal-1.0.2 \
		pin-utils-0.1.0 \
		pkg-config-0.3.19 \
		pretty-hex-0.2.1 \
		proc-macro-crate-0.1.5 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.24 \
		quote-1.0.7 \
		regex-1.4.2 \
		regex-syntax-0.6.21 \
		rustc_version-0.2.3 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serde-1.0.118 \
		slab-0.4.2 \
		smallvec-1.5.1 \
		strum-0.20.0 \
		strum_macros-0.20.1 \
		syn-1.0.54 \
		system-deps-2.0.2 \
		thiserror-1.0.22 \
		thiserror-impl-1.0.22 \
		thread_local-1.0.1 \
		toml-0.5.7 \
		unicode-segmentation-1.7.1 \
		unicode-xid-0.2.1 \
		version-compare-0.0.11 \
		version_check-0.9.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		gdk4,gdk4-sys,gsk4,gsk4-sys,gtk4,gtk4-macros,gtk4-sys@git+https://github.com/gtk-rs/gtk4-rs\#64d0e1c1344458a065ccf22dcecf105c55b902ca \
		gstreamer,gstreamer-base,gstreamer-base-sys,gstreamer-player,gstreamer-player-sys,gstreamer-sys,gstreamer-video,gstreamer-video-sys@git+https://gitlab.freedesktop.org/gstreamer/gstreamer-rs\#0e8b95f1d029530ad3f84a3f08a20d8dfd80a089 \
		cairo-rs,cairo-sys-rs,gdk-pixbuf,gdk-pixbuf-sys,gio,gio-sys,glib,glib-macros,glib-sys,gobject-sys,graphene-rs,graphene-sys,pango,pango-sys@git+https://github.com/gtk-rs/gtk3-rs\#c58fab4fec1254244f598c4eac7f9310184c5996 \
		libadwaita,libadwaita-sys@git+https://gitlab.gnome.org/bilelmoussaoui/libadwaita-rs\#b898c11fb6776fc7a9a6b920222fa3173216a80c
CARGO_BUILD=	no
CARGO_INSTALL=	no
CARGO_TEST=	no

pre-patch:
# Chase gtk-rs -> gtk3-rs rename for USES=cargo patching
	@${GREP} --include='*/Cargo.toml' -lr 'git.*gtk-rs' ${WRKDIR} | ${XARGS} ${REINPLACE_CMD} \
		's,\(gtk-rs\)/gtk-rs,\1/gtk3-rs,'

post-patch:
# Make each cargo subcommand very verbose
	@${REINPLACE_CMD} -e '/cargo/s/ --/&verbose&verbose&/' \
		${WRKSRC}/build-aux/cargo.sh

.include <bsd.port.mk>
