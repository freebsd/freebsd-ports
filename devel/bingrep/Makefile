PORTNAME=	bingrep
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
CATEGORIES=	devel

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Grep through binaries

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo cpe
CPE_VENDOR=	bingrep_project
USE_GITHUB=	yes
GH_ACCOUNT=	m4b

CARGO_CRATES=	aho-corasick-0.7.18 \
		anyhow-1.0.56 \
		arrayref-0.3.6 \
		arrayvec-0.5.2 \
		atty-0.2.14 \
		autocfg-1.1.0 \
		base64-0.13.0 \
		bitflags-1.3.2 \
		blake2b_simd-0.5.11 \
		bstr-0.2.17 \
		byteorder-1.4.3 \
		cfg-if-1.0.0 \
		clap-3.1.6 \
		clap_derive-3.1.4 \
		constant_time_eq-0.1.5 \
		cpp_demangle-0.3.5 \
		crossbeam-utils-0.8.8 \
		csv-1.1.6 \
		csv-core-0.1.10 \
		dirs-1.0.5 \
		encode_unicode-0.3.6 \
		env_logger-0.9.0 \
		fuchsia-cprng-0.1.1 \
		getrandom-0.1.16 \
		goblin-0.5.1 \
		hashbrown-0.11.2 \
		heck-0.4.0 \
		hermit-abi-0.1.19 \
		hexplay-0.2.1 \
		humantime-2.1.0 \
		indexmap-1.8.0 \
		itoa-0.4.8 \
		lazy_static-1.4.0 \
		libc-0.2.121 \
		log-0.4.14 \
		memchr-2.4.1 \
		memrange-0.1.3 \
		metagoblin-0.6.0 \
		os_str_bytes-6.0.0 \
		plain-0.2.3 \
		prettytable-rs-0.8.0 \
		proc-macro-error-1.0.4 \
		proc-macro-error-attr-1.0.4 \
		proc-macro2-1.0.36 \
		quote-1.0.16 \
		rand-0.3.23 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.2 \
		rdrand-0.4.0 \
		redox_syscall-0.1.57 \
		redox_users-0.3.5 \
		regex-1.5.5 \
		regex-automata-0.1.10 \
		regex-syntax-0.6.25 \
		rust-argon2-0.8.3 \
		rustc-demangle-0.1.21 \
		rustc-serialize-0.3.24 \
		ryu-1.0.9 \
		scroll-0.11.0 \
		scroll_derive-0.11.0 \
		serde-1.0.136 \
		strsim-0.10.0 \
		syn-1.0.89 \
		term-0.5.2 \
		termcolor-0.3.6 \
		termcolor-1.1.3 \
		terminal_size-0.1.17 \
		textwrap-0.15.0 \
		theban_interval_tree-0.7.1 \
		time-0.1.44 \
		unicode-width-0.1.9 \
		unicode-xid-0.2.2 \
		version_check-0.9.4 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		wasi-0.10.0+wasi-snapshot-preview1 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		wincolor-0.1.6

PLIST_FILES=	bin/bingrep

PORTDOCS=	README.md
PORTEXAMPLES=	etc/*.png

OPTIONS_DEFINE=	DOCS EXAMPLES

EXAMPLES_PLIST_FILES=	${EXAMPLESDIR}/archive.png \
			${EXAMPLESDIR}/elf_table1.png \
			${EXAMPLESDIR}/elf_table2.png \
			${EXAMPLESDIR}/mach.png \
			${EXAMPLESDIR}/ranges.png

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/etc && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
