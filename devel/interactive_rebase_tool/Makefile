# $FreeBSD$

PORTNAME=	interactive_rebase_tool
DISTVERSION=	2.0.0
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Improved sequence editor for Git

LICENSE=	GPLv3+

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	MitMaro
GH_PROJECT=	git-interactive-rebase-tool

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.38 \
		arrayvec-0.4.12 \
		atty-0.2.14 \
		autocfg-1.0.1 \
		bitflags-1.2.1 \
		cc-1.0.66 \
		cfg-if-0.1.10 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		clap-2.33.3 \
		concat-idents-1.1.2 \
		crossterm-0.19.0 \
		crossterm_winapi-0.7.0 \
		form_urlencoded-1.0.0 \
		getrandom-0.2.2 \
		git2-0.13.17 \
		hermit-abi-0.1.18 \
		idna-0.2.0 \
		instant-0.1.9 \
		itoa-0.4.7 \
		jobserver-0.1.21 \
		lazy_static-1.4.0 \
		libc-0.2.82 \
		libgit2-sys-0.12.18+1.1.0 \
		libz-sys-1.1.2 \
		lock_api-0.4.2 \
		log-0.4.14 \
		matches-0.1.8 \
		mio-0.7.7 \
		miow-0.3.6 \
		nodrop-0.1.14 \
		ntapi-0.3.6 \
		num-format-0.4.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		parking_lot-0.11.1 \
		parking_lot_core-0.8.2 \
		percent-encoding-2.1.0 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.10 \
		proc-macro2-1.0.24 \
		quote-1.0.8 \
		rand-0.8.3 \
		rand_chacha-0.3.0 \
		rand_core-0.6.1 \
		rand_hc-0.3.0 \
		redox_syscall-0.1.57 \
		redox_syscall-0.2.4 \
		remove_dir_all-0.5.3 \
		rstest-0.6.4 \
		rustc_version-0.2.3 \
		scopeguard-1.1.0 \
		semver-0.9.0 \
		semver-parser-0.7.0 \
		serial_test-0.5.1 \
		serial_test_derive-0.5.1 \
		signal-hook-0.1.17 \
		signal-hook-registry-1.3.0 \
		smallvec-1.6.1 \
		socket2-0.3.19 \
		strsim-0.8.0 \
		syn-1.0.60 \
		tempfile-3.2.0 \
		textwrap-0.11.0 \
		time-0.1.43 \
		tinyvec-1.1.1 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.16 \
		unicode-segmentation-1.7.1 \
		unicode-width-0.1.8 \
		unicode-xid-0.2.1 \
		url-2.2.0 \
		vcpkg-0.2.11 \
		vec_map-0.8.2 \
		wasi-0.10.1+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xi-unicode-0.3.0

PLIST_FILES=	bin/interactive-rebase-tool \
		man/man1/interactive-rebase-tool.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/interactive-rebase-tool
	${INSTALL_MAN} ${WRKSRC}/src/interactive-rebase-tool.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
