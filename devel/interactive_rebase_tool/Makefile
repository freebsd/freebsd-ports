PORTNAME=	interactive_rebase_tool
DISTVERSION=	2.2.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Improved sequence editor for Git

LICENSE=	GPLv3+

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	MitMaro
GH_PROJECT=	git-interactive-rebase-tool

CARGO_CRATES=	ansi_term-0.12.1 \
		anyhow-1.0.57 \
		arrayvec-0.4.12 \
		autocfg-1.0.1 \
		bitflags-1.3.2 \
		captur-0.1.0 \
		cc-1.0.68 \
		cfg-if-1.0.0 \
		chrono-0.4.19 \
		crossbeam-channel-0.5.4 \
		crossbeam-utils-0.8.6 \
		crossterm-0.23.2 \
		crossterm_winapi-0.9.0 \
		ctor-0.1.21 \
		diff-0.1.12 \
		fastrand-1.6.0 \
		form_urlencoded-1.0.1 \
		getrandom-0.2.3 \
		git2-0.14.2 \
		idna-0.2.3 \
		instant-0.1.9 \
		itoa-0.4.7 \
		jobserver-0.1.22 \
		lazy_static-1.4.0 \
		libc-0.2.97 \
		libgit2-sys-0.13.2+1.4.2 \
		libz-sys-1.1.3 \
		lock_api-0.4.6 \
		log-0.4.14 \
		matches-0.1.8 \
		mio-0.8.2 \
		miow-0.3.7 \
		nodrop-0.1.14 \
		ntapi-0.3.6 \
		num-format-0.4.0 \
		num-integer-0.1.44 \
		num-traits-0.2.14 \
		output_vt100-0.1.2 \
		parking_lot-0.11.2 \
		parking_lot-0.12.0 \
		parking_lot_core-0.8.5 \
		parking_lot_core-0.9.0 \
		percent-encoding-2.1.0 \
		pico-args-0.4.2 \
		pkg-config-0.3.19 \
		ppv-lite86-0.2.16 \
		pretty_assertions-1.2.1 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.27 \
		quote-1.0.9 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.3 \
		redox_syscall-0.2.9 \
		remove_dir_all-0.5.3 \
		rstest-0.11.0 \
		rstest-0.12.0 \
		rustc_version-0.4.0 \
		rustversion-1.0.6 \
		scopeguard-1.1.0 \
		semver-1.0.3 \
		serial_test-0.6.0 \
		serial_test_derive-0.6.0 \
		signal-hook-0.3.13 \
		signal-hook-mio-0.2.3 \
		signal-hook-registry-1.4.0 \
		smallvec-1.6.1 \
		syn-1.0.73 \
		tempfile-3.3.0 \
		time-0.1.43 \
		tinyvec-1.2.0 \
		tinyvec_macros-0.1.0 \
		unicode-bidi-0.3.5 \
		unicode-normalization-0.1.19 \
		unicode-segmentation-1.9.0 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		url-2.2.2 \
		uuid-1.0.0 \
		vcpkg-0.2.15 \
		version_check-0.9.4 \
		wasi-0.10.2+wasi-snapshot-preview1 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.29.0 \
		windows_aarch64_msvc-0.29.0 \
		windows_i686_gnu-0.29.0 \
		windows_i686_msvc-0.29.0 \
		windows_x86_64_gnu-0.29.0 \
		windows_x86_64_msvc-0.29.0 \
		xi-unicode-0.3.0

PLIST_FILES=	bin/interactive-rebase-tool \
		man/man1/interactive-rebase-tool.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/interactive-rebase-tool
	${INSTALL_MAN} ${WRKSRC}/src/interactive-rebase-tool.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
