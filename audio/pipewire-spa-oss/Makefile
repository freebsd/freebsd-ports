PORTNAME=	pipewire-spa-oss
DISTVERSION=	g20250416
PORTREVISION=	2
CATEGORIES=	audio

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	PipeWire SPA plugin implementing a FreeBSD OSS backend
WWW=		https://github.com/shkhln/pw-oss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 riscv64 riscv64sf

LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire

USES=		cargo llvm:lib,noexport

USE_GITHUB=	yes
GH_ACCOUNT=	shkhln
GH_PROJECT=	pw-oss
GH_TAGNAME=	2fd15da459d6ed099a276ec6428301e8ac43bfb4

CARGO_CRATES=	aho-corasick-1.1.3 \
		annotate-snippets-0.9.2 \
		autocfg-1.3.0 \
		bindgen-0.69.4 \
		bitflags-2.6.0 \
		cc-1.1.21 \
		cexpr-0.6.0 \
		cfg-expr-0.15.8 \
		cfg-if-1.0.0 \
		clang-sys-1.8.1 \
		convert_case-0.6.0 \
		cookie-factory-0.3.3 \
		either-1.13.0 \
		equivalent-1.0.1 \
		futures-0.3.30 \
		futures-channel-0.3.30 \
		futures-core-0.3.30 \
		futures-executor-0.3.30 \
		futures-io-0.3.30 \
		futures-macro-0.3.30 \
		futures-sink-0.3.30 \
		futures-task-0.3.30 \
		futures-util-0.3.30 \
		glob-0.3.1 \
		hashbrown-0.14.5 \
		heck-0.5.0 \
		indexmap-2.5.0 \
		itertools-0.12.1 \
		lazy_static-1.5.0 \
		lazycell-1.3.0 \
		libc-0.2.159 \
		libloading-0.8.5 \
		memchr-2.7.4 \
		minimal-lexical-0.2.1 \
		nix-0.27.1 \
		nom-7.1.3 \
		pin-project-lite-0.2.14 \
		pin-utils-0.1.0 \
		pkg-config-0.3.31 \
		proc-macro2-1.0.86 \
		quote-1.0.37 \
		regex-1.10.6 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		rustc-hash-1.1.0 \
		serde-1.0.210 \
		serde_derive-1.0.210 \
		serde_spanned-0.6.7 \
		shlex-1.3.0 \
		slab-0.4.9 \
		smallvec-1.13.2 \
		syn-2.0.77 \
		system-deps-6.2.2 \
		target-lexicon-0.12.16 \
		toml-0.8.19 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.22 \
		uds-0.4.2 \
		unicode-ident-1.0.13 \
		unicode-segmentation-1.12.0 \
		unicode-width-0.1.14 \
		version-compare-0.2.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.19 \
		yansi-term-0.1.2 \
		libspa,libspa-sys@git+https://gitlab.freedesktop.org/pipewire/pipewire-rs.git?rev=016e554768ae251c8de3724ea4b06f4749a8dd00\#016e554768ae251c8de3724ea4b06f4749a8dd00

PLIST_FILES=	lib/spa-0.2/libspa_freebsd_oss.so \
		share/pipewire/pipewire.conf.d/oss.conf \
		share/wireplumber/scripts/monitors/oss.lua \
		share/wireplumber/wireplumber.conf.d/oss.conf

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/spa-0.2
	${INSTALL_LIB} ${WRKDIR}/target/release/libspa_freebsd_oss.so ${STAGEDIR}${PREFIX}/lib/spa-0.2

	${MKDIR} ${STAGEDIR}${PREFIX}/share/pipewire/pipewire.conf.d
	${INSTALL_DATA} ${WRKSRC}/conf/pipewire/pipewire.conf.d/oss.conf ${STAGEDIR}${PREFIX}/share/pipewire/pipewire.conf.d

	${MKDIR} ${STAGEDIR}${PREFIX}/share/wireplumber/wireplumber.conf.d
	${INSTALL_DATA} ${WRKSRC}/conf/wireplumber/wireplumber.conf.d/oss.conf ${STAGEDIR}${PREFIX}/share/wireplumber/wireplumber.conf.d

	${MKDIR} ${STAGEDIR}${PREFIX}/share/wireplumber/scripts/monitors
	${INSTALL_DATA} ${WRKSRC}/share/wireplumber/scripts/monitors/oss.lua ${STAGEDIR}${PREFIX}/share/wireplumber/scripts/monitors

.include <bsd.port.mk>
