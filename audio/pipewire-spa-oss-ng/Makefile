PORTNAME=	pipewire-spa-oss-ng
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.4
CATEGORIES=	audio

MAINTAINER=	kbowling@FreeBSD.org
COMMENT=	PipeWire SPA plugin implementing a FreeBSD OSS backend
WWW=		https://github.com/kev009/pw-oss

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 powerpc64 powerpc64le riscv64

LIB_DEPENDS=	libpipewire-0.3.so:multimedia/pipewire

USES=		cargo llvm:lib,noexport

USE_GITHUB=	yes
GH_ACCOUNT=	kev009
GH_PROJECT=	pw-oss

CARGO_CRATES=	aho-corasick-1.1.4 \
		annotate-snippets-0.11.5 \
		anstyle-1.0.14 \
		bindgen-0.72.1 \
		bitflags-2.13.0 \
		cc-1.2.65 \
		cexpr-0.6.0 \
		cfg-expr-0.20.8 \
		cfg-if-1.0.4 \
		cfg_aliases-0.2.1 \
		clang-sys-1.8.1 \
		cookie-factory-0.3.3 \
		either-1.16.0 \
		equivalent-1.0.2 \
		errno-0.3.14 \
		find-msvc-tools-0.1.9 \
		glob-0.3.3 \
		hashbrown-0.17.1 \
		heck-0.5.0 \
		indexmap-2.14.0 \
		itertools-0.13.0 \
		libc-0.2.186 \
		libloading-0.8.9 \
		libspa-0.10.0 \
		libspa-sys-0.10.0 \
		linux-raw-sys-0.12.1 \
		memchr-2.8.2 \
		minimal-lexical-0.2.1 \
		nix-0.31.3 \
		nom-7.1.3 \
		nom-8.0.0 \
		pkg-config-0.3.33 \
		proc-macro2-1.0.106 \
		quote-1.0.46 \
		regex-1.12.4 \
		regex-automata-0.4.14 \
		regex-syntax-0.8.11 \
		rustc-hash-2.1.2 \
		rustix-1.1.4 \
		serde_core-1.0.228 \
		serde_derive-1.0.228 \
		serde_spanned-1.1.1 \
		shlex-1.3.0 \
		shlex-2.0.1 \
		smallvec-1.15.2 \
		syn-2.0.118 \
		system-deps-7.0.8 \
		target-lexicon-0.13.5 \
		toml-1.1.2+spec-1.1.0 \
		toml_datetime-1.1.1+spec-1.1.0 \
		toml_parser-1.1.2+spec-1.1.0 \
		toml_writer-1.1.1+spec-1.1.0 \
		uds-0.4.2 \
		unicode-ident-1.0.24 \
		unicode-width-0.2.2 \
		version-compare-0.2.1 \
		windows-link-0.2.1 \
		windows-sys-0.61.2 \
		winnow-1.0.3

CONFLICTS_INSTALL=	pipewire-spa-oss

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
