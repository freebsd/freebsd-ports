PORTNAME=	git-repo-manager
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.17
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Git tool to manage worktrees and integrate with GitHub and GitLab
WWW=		https://hakoerber.github.io/git-repo-manager/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase

USE_GITHUB=	yes
GH_ACCOUNT=	hakoerber

CARGO_CRATES=	adler-1.0.2 \
		aho-corasick-1.1.3 \
		anstream-0.6.15 \
		anstyle-1.0.8 \
		anstyle-parse-0.2.5 \
		anstyle-query-1.1.1 \
		anstyle-wincon-3.0.4 \
		autocfg-1.3.0 \
		base64-0.22.1 \
		bitflags-2.6.0 \
		byteorder-1.5.0 \
		bytes-1.7.1 \
		cc-1.1.12 \
		cfg-if-1.0.0 \
		clap-4.4.18 \
		clap_builder-4.4.18 \
		clap_derive-4.4.7 \
		clap_lex-0.6.0 \
		colorchoice-1.0.2 \
		comfy-table-7.1.1 \
		console-0.15.8 \
		crc32fast-1.4.2 \
		crossterm-0.27.0 \
		crossterm_winapi-0.9.1 \
		dirs-5.0.1 \
		dirs-sys-0.4.1 \
		encode_unicode-0.3.6 \
		equivalent-1.0.1 \
		flate2-1.0.31 \
		fnv-1.0.7 \
		form_urlencoded-1.2.1 \
		getrandom-0.2.15 \
		git2-0.19.0 \
		hashbrown-0.14.5 \
		heck-0.4.1 \
		heck-0.5.0 \
		http-0.2.12 \
		idna-0.5.0 \
		indexmap-2.4.0 \
		is_terminal_polyfill-1.70.1 \
		itoa-1.0.11 \
		jobserver-0.1.32 \
		lazy_static-1.5.0 \
		libc-0.2.155 \
		libgit2-sys-0.17.0+1.8.1 \
		libredox-0.1.3 \
		libssh2-sys-0.3.0 \
		libz-sys-1.1.19 \
		lock_api-0.4.12 \
		log-0.4.22 \
		memchr-2.7.4 \
		miniz_oxide-0.7.4 \
		once_cell-1.19.0 \
		openssl-probe-0.1.5 \
		openssl-src-300.3.1+3.3.1 \
		openssl-sys-0.9.103 \
		option-ext-0.2.0 \
		outdir-tempdir-0.2.0 \
		parking_lot-0.12.3 \
		parking_lot_core-0.9.10 \
		parse_link_header-0.3.3 \
		percent-encoding-2.3.1 \
		pkg-config-0.3.30 \
		ppv-lite86-0.2.20 \
		proc-macro2-1.0.86 \
		quote-1.0.36 \
		rand-0.8.5 \
		rand_chacha-0.3.1 \
		rand_core-0.6.4 \
		redox_syscall-0.5.3 \
		redox_users-0.4.5 \
		regex-1.10.6 \
		regex-automata-0.4.7 \
		regex-syntax-0.8.4 \
		ring-0.17.8 \
		rustls-0.23.12 \
		rustls-pki-types-1.8.0 \
		rustls-webpki-0.102.6 \
		rustversion-1.0.17 \
		ryu-1.0.18 \
		scopeguard-1.2.0 \
		serde-1.0.207 \
		serde_derive-1.0.207 \
		serde_json-1.0.125 \
		serde_spanned-0.6.7 \
		serde_yaml-0.9.34+deprecated \
		shellexpand-3.1.0 \
		shlex-1.3.0 \
		smallvec-1.13.2 \
		spin-0.9.8 \
		strsim-0.10.0 \
		strum-0.26.3 \
		strum_macros-0.26.4 \
		subtle-2.6.1 \
		syn-2.0.74 \
		thiserror-1.0.63 \
		thiserror-impl-1.0.63 \
		tinyvec-1.8.0 \
		tinyvec_macros-0.1.1 \
		toml-0.8.19 \
		toml_datetime-0.6.8 \
		toml_edit-0.22.20 \
		unicode-bidi-0.3.15 \
		unicode-ident-1.0.12 \
		unicode-normalization-0.1.23 \
		unicode-width-0.1.13 \
		unsafe-libyaml-0.2.11 \
		untrusted-0.9.0 \
		ureq-2.10.1 \
		url-2.5.2 \
		url-escape-0.1.1 \
		utf8parse-0.2.2 \
		uuid-1.10.0 \
		vcpkg-0.2.15 \
		wasi-0.11.0+wasi-snapshot-preview1 \
		webpki-roots-0.26.3 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		windows-sys-0.48.0 \
		windows-sys-0.52.0 \
		windows-targets-0.48.5 \
		windows-targets-0.52.6 \
		windows_aarch64_gnullvm-0.48.5 \
		windows_aarch64_gnullvm-0.52.6 \
		windows_aarch64_msvc-0.48.5 \
		windows_aarch64_msvc-0.52.6 \
		windows_i686_gnu-0.48.5 \
		windows_i686_gnu-0.52.6 \
		windows_i686_gnullvm-0.52.6 \
		windows_i686_msvc-0.48.5 \
		windows_i686_msvc-0.52.6 \
		windows_x86_64_gnu-0.48.5 \
		windows_x86_64_gnu-0.52.6 \
		windows_x86_64_gnullvm-0.48.5 \
		windows_x86_64_gnullvm-0.52.6 \
		windows_x86_64_msvc-0.48.5 \
		windows_x86_64_msvc-0.52.6 \
		winnow-0.6.18 \
		zerocopy-0.7.35 \
		zerocopy-derive-0.7.35 \
		zeroize-1.8.1

OPENSSLINC=	/usr/include
OPENSSLLIB=	/usr/lib

PLIST_FILES=	bin/grm

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/grm

.include <bsd.port.mk>
