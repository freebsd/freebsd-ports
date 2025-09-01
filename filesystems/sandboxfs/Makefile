PORTNAME=	sandboxfs
DISTVERSIONPREFIX=	sandboxfs-
DISTVERSION=	0.2.0
PORTREVISION=	50
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual file system for sandboxing
WWW=		https://github.com/bazelbuild/sandboxfs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo fuse
USE_GITHUB=	yes
GH_ACCOUNT=	bazelbuild

CARGO_CRATES=	aho-corasick-0.7.10 \
		arc-swap-0.4.5 \
		atty-0.2.14 \
		backtrace-0.3.46 \
		backtrace-sys-0.1.35 \
		bitflags-1.2.1 \
		cc-1.0.50 \
		cfg-if-0.1.10 \
		cpuprofiler-0.0.4 \
		env_logger-0.5.13 \
		error-chain-0.12.2 \
		failure-0.1.7 \
		failure_derive-0.1.7 \
		fuse-0.3.1 \
		getopts-0.2.21 \
		getrandom-0.1.14 \
		hermit-abi-0.1.11 \
		humantime-1.3.0 \
		itoa-0.4.5 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		log-0.3.9 \
		log-0.4.8 \
		memchr-2.3.3 \
		nix-0.12.1 \
		num_cpus-1.13.0 \
		pkg-config-0.3.17 \
		ppv-lite86-0.2.6 \
		proc-macro2-1.0.10 \
		quick-error-1.2.3 \
		quote-1.0.3 \
		rand-0.7.3 \
		rand_chacha-0.2.2 \
		rand_core-0.5.1 \
		rand_hc-0.2.0 \
		redox_syscall-0.1.56 \
		regex-1.3.7 \
		regex-syntax-0.6.17 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.16 \
		ryu-1.0.3 \
		serde-1.0.106 \
		serde_derive-1.0.106 \
		serde_json-1.0.51 \
		signal-hook-0.1.13 \
		signal-hook-registry-1.2.0 \
		syn-1.0.17 \
		synstructure-0.12.3 \
		tempfile-3.1.0 \
		termcolor-1.1.0 \
		thread-scoped-1.0.2 \
		thread_local-1.0.1 \
		threadpool-1.7.1 \
		time-0.1.43 \
		unicode-width-0.1.7 \
		unicode-xid-0.2.0 \
		users-0.9.1 \
		version_check-0.9.1 \
		void-1.0.2 \
		wasi-0.9.0+wasi-snapshot-preview1 \
		winapi-0.3.8 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-util-0.1.5 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		xattr-0.2.2

PLIST_FILES=	bin/sandboxfs \
		share/man/man1/sandboxfs.1.gz

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/sandboxfs.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
