PORTNAME=	rpg-cli
DISTVERSION=	1.0.1
PORTREVISION=	31
CATEGORIES=	games

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Your filesystem as a dungeon
WWW=		https://github.com/facundoolano/rpg-cli

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	facundoolano

CARGO_CRATES=	anyhow-1.0.43 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bincode-1.3.3 \
		bitflags-1.3.2 \
		cfg-if-1.0.0 \
		clap-3.0.0-beta.4 \
		clap_derive-3.0.0-beta.4 \
		colored-2.0.0 \
		ctor-0.1.20 \
		dirs-3.0.2 \
		dirs-sys-0.3.6 \
		dtoa-0.4.8 \
		dunce-1.0.2 \
		erased-serde-0.3.16 \
		getrandom-0.2.3 \
		ghost-0.1.2 \
		hashbrown-0.11.2 \
		heck-0.3.3 \
		hermit-abi-0.1.19 \
		indexmap-1.7.0 \
		inventory-0.1.10 \
		inventory-impl-0.1.10 \
		itoa-0.4.7 \
		lazy_static-1.4.0 \
		libc-0.2.99 \
		linked-hash-map-0.5.4 \
		once_cell-1.8.0 \
		os_str_bytes-3.1.0 \
		ppv-lite86-0.2.10 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.28 \
		quote-1.0.9 \
		rand-0.8.4 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		rand_hc-0.3.1 \
		redox_syscall-0.2.10 \
		redox_users-0.4.0 \
		ryu-1.0.5 \
		serde-1.0.127 \
		serde_derive-1.0.127 \
		serde_json-1.0.66 \
		serde_yaml-0.8.18 \
		strsim-0.10.0 \
		strum-0.21.0 \
		strum_macros-0.21.1 \
		syn-1.0.75 \
		termcolor-1.1.2 \
		textwrap-0.14.2 \
		typetag-0.1.7 \
		typetag-impl-0.1.7 \
		unicode-segmentation-1.8.0 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.2 \
		vec_map-0.8.2 \
		version_check-0.9.3 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yaml-rust-0.4.5

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
