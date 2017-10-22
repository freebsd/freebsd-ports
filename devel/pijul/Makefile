# Created by: Carlo Strub
# $FreeBSD$

PORTNAME=	pijul
PORTVERSION=	0.8.0
CATEGORIES=	devel
MASTER_SITES=	https://pijul.org/releases/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	cs@FreeBSD.org
COMMENT=	Distributed version control system

LICENSE=	GPLv2

USES=		cargo gmake
CARGO_CRATES=	advapi32-sys-0.2.0 \
		aho-corasick-0.6.3 \
		ansi_term-0.9.0 \
		arrayref-0.3.4 \
		atty-0.2.2 \
		backtrace-0.3.3 \
		backtrace-sys-0.1.12 \
		base64-0.6.0 \
		bincode-0.8.0 \
		bitflags-0.4.0 \
		bitflags-0.7.0 \
		bitflags-0.9.1 \
		bytecount-0.1.7 \
		byteorder-1.1.0 \
		bytes-0.4.5 \
		cfg-if-0.1.2 \
		chrono-0.4.0 \
		clap-2.26.0 \
		coco-0.1.1 \
		conv-0.3.3 \
		crossbeam-0.2.10 \
		cryptovec-0.3.4 \
		custom_derive-0.1.7 \
		dbghelp-sys-0.2.0 \
		either-1.1.0 \
		encode_unicode-0.1.3 \
		env_logger-0.4.3 \
		errno-0.2.3 \
		error-chain-0.10.0 \
		filetime-0.1.10 \
		flate2-0.2.19 \
		fnv-1.0.5 \
		fs2-0.4.2 \
		futures-0.1.15 \
		futures-cpupool-0.1.5 \
		gcc-0.3.54 \
		getch-0.2.0 \
		globset-0.2.0 \
		hex-0.2.0 \
		httparse-1.2.3 \
		hyper-0.11.2 \
		hyper-rustls-0.8.0 \
		ignore-0.2.2 \
		iovec-0.1.0 \
		isatty-0.1.3 \
		kernel32-sys-0.2.2 \
		language-tags-0.2.2 \
		lazy_static-0.2.8 \
		lazycell-0.5.1 \
		libc-0.2.30 \
		liner-0.4.1 \
		log-0.3.8 \
		magenta-0.1.1 \
		magenta-sys-0.1.1 \
		memchr-1.0.1 \
		memmap-0.5.2 \
		mime-0.3.3 \
		miniz-sys-0.1.9 \
		mio-0.6.10 \
		mio-uds-0.6.4 \
		miow-0.2.1 \
		net2-0.2.31 \
		nix-0.5.1 \
		num-0.1.40 \
		num-integer-0.1.35 \
		num-iter-0.1.34 \
		num-traits-0.1.40 \
		num_cpus-1.6.2 \
		pager-0.12.1 \
		percent-encoding-1.0.0 \
		progrs-0.1.1 \
		quote-0.3.15 \
		rand-0.3.16 \
		rayon-0.7.1 \
		rayon-core-1.2.1 \
		redox_syscall-0.1.31 \
		redox_termios-0.1.1 \
		regex-0.2.2 \
		regex-syntax-0.4.1 \
		ring-0.11.0 \
		rust-crypto-0.2.36 \
		rustc-demangle-0.1.5 \
		rustc-serialize-0.3.24 \
		rustc_version-0.1.7 \
		rustls-0.9.0 \
		rustyline-1.0.0 \
		safemem-0.2.0 \
		same-file-0.1.3 \
		sanakirja-0.8.12 \
		scoped-tls-0.1.0 \
		scopeguard-0.3.2 \
		semver-0.1.20 \
		serde-1.0.14 \
		serde_derive-1.0.14 \
		serde_derive_internals-0.16.0 \
		shell-escape-0.1.3 \
		slab-0.3.0 \
		smallvec-0.2.1 \
		strsim-0.6.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		take-0.1.0 \
		tar-0.4.13 \
		tempdir-0.3.5 \
		term-0.4.6 \
		term_size-0.3.0 \
		termion-1.5.1 \
		termios-0.2.2 \
		textwrap-0.7.0 \
		thread_local-0.3.4 \
		thrussh-0.13.3 \
		thrussh-keys-0.4.0 \
		time-0.1.38 \
		tokio-core-0.1.9 \
		tokio-io-0.1.3 \
		tokio-proto-0.1.1 \
		tokio-rustls-0.2.4 \
		tokio-service-0.1.0 \
		tokio-uds-0.1.5 \
		toml-0.4.5 \
		unicase-2.0.0 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unreachable-1.0.0 \
		untrusted-0.5.1 \
		username-0.2.0 \
		utf8-ranges-1.0.0 \
		vec_map-0.8.0 \
		void-1.0.2 \
		walkdir-1.0.7 \
		webpki-0.14.0 \
		webpki-roots-0.11.0 \
		winapi-0.2.8 \
		winapi-build-0.1.1 \
		ws2_32-sys-0.2.1 \
		xattr-0.1.11

PLIST_FILES=	bin/pijul \
		man/man1/pijul-show-dependencies.1.gz
WRKSRC_SUBDIR=	pijul

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pijul
	${INSTALL_MAN} ${WRKDIR}/${DISTNAME}/man/en/man1/pijul-show-dependencies.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
