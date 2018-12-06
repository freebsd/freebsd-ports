# $FreeBSD$

PORTNAME=	genact
DISTVERSION=	0.6.0
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Nonsense activity generator

LICENSE=	APACHE20 BSD3CLAUSE ISCL MIT UNLICENSE
LICENSE_COMB=	multi
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE

USES=	cargo
USE_GITHUB=	yes
GH_ACCOUNT=	svenstaro

PLIST_FILES=	bin/genact

CARGO_CRATES=	aho-corasick-0.6.4 \
		ansi_term-0.11.0 \
		aster-0.41.0 \
		atty-0.2.10 \
		base-x-0.2.2 \
		bindgen-0.24.0 \
		bitflags-0.8.2 \
		bitflags-0.9.1 \
		bitflags-1.0.3 \
		cexpr-0.2.3 \
		cfg-if-0.1.3 \
		chrono-0.4.2 \
		clang-sys-0.16.0 \
		clap-2.31.2 \
		cloudabi-0.0.3 \
		ctrlc-3.1.0 \
		discard-1.0.3 \
		dtoa-0.4.2 \
		emscripten-sys-0.3.2 \
		env_logger-0.4.3 \
		fake-1.2.2 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		glob-0.2.11 \
		humantime-1.1.1 \
		idna-0.1.4 \
		itoa-0.4.1 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.11 \
		lazy_static-1.0.1 \
		libc-0.2.42 \
		libloading-0.4.3 \
		log-0.3.9 \
		log-0.4.1 \
		matches-0.1.6 \
		memchr-1.0.2 \
		memchr-2.0.1 \
		nix-0.9.0 \
		nom-3.2.1 \
		num-integer-0.1.38 \
		num-traits-0.2.4 \
		pbr-1.0.1 \
		percent-encoding-1.0.1 \
		proc-macro2-0.2.3 \
		proc-macro2-0.4.5 \
		quasi-0.32.0 \
		quasi_codegen-0.32.0 \
		quick-error-1.2.2 \
		quote-0.4.2 \
		quote-0.6.3 \
		rand-0.3.22 \
		rand-0.4.2 \
		rand-0.5.0 \
		rand_core-0.2.0 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		regex-0.2.11 \
		regex-1.0.0 \
		regex-syntax-0.5.6 \
		regex-syntax-0.6.0 \
		rustc-serialize-0.3.24 \
		serde-1.0.66 \
		serde_derive-1.0.66 \
		serde_json-1.0.19 \
		stdweb-0.4.6 \
		stdweb-derive-0.4.0 \
		stdweb-internal-macros-0.1.0 \
		strsim-0.7.0 \
		syn-0.12.15 \
		syn-0.14.2 \
		syntex-0.58.1 \
		syntex_errors-0.58.1 \
		syntex_pos-0.58.1 \
		syntex_syntax-0.58.1 \
		term-0.4.6 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		time-0.1.40 \
		ucd-util-0.1.1 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.5 \
		unicode-xid-0.0.4 \
		unicode-xid-0.1.0 \
		unreachable-1.0.0 \
		url-1.7.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.1 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		yansi-0.4.0

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/genact

.include <bsd.port.mk>
