# $FreeBSD$

PORTNAME=	git-absorb
DISTVERSION=	0.5.0
PORTREVISION=	3
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Git command for automating fixup/autosquash commits

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	tummychow

CARGO_CRATES=	ansi_term-0.10.2 \
		atty-0.2.12 \
		autocfg-0.1.4 \
		backtrace-0.3.32 \
		backtrace-sys-0.1.30 \
		bitflags-1.1.0 \
		cc-1.0.37 \
		cfg-if-0.1.9 \
		chrono-0.4.7 \
		clap-2.30.0 \
		failure-0.1.5 \
		failure_derive-0.1.5 \
		fuchsia-cprng-0.1.1 \
		git2-0.9.1 \
		idna-0.1.5 \
		isatty-0.1.9 \
		kernel32-sys-0.2.2 \
		lazy_static-1.3.0 \
		libc-0.2.59 \
		libgit2-sys-0.8.1 \
		libz-sys-1.0.25 \
		log-0.4.7 \
		matches-0.1.8 \
		memchr-2.0.2 \
		num-integer-0.1.41 \
		num-traits-0.2.8 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		proc-macro2-0.4.30 \
		quote-0.6.13 \
		rand-0.4.6 \
		rand_core-0.3.1 \
		rand_core-0.4.0 \
		rdrand-0.4.0 \
		redox_syscall-0.1.56 \
		remove_dir_all-0.5.2 \
		rustc-demangle-0.1.15 \
		slog-2.1.1 \
		slog-async-2.2.0 \
		slog-term-2.3.0 \
		smallvec-0.6.10 \
		strsim-0.7.0 \
		syn-0.15.39 \
		synstructure-0.10.2 \
		take_mut-0.2.2 \
		tempdir-0.3.7 \
		term-0.4.6 \
		textwrap-0.9.0 \
		thread_local-0.3.6 \
		time-0.1.42 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-width-0.1.5 \
		unicode-xid-0.1.0 \
		url-1.7.2 \
		vcpkg-0.2.7 \
		vec_map-0.8.1 \
		winapi-0.2.8 \
		winapi-0.3.7 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/git-absorb

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/git-absorb

.include <bsd.port.mk>
