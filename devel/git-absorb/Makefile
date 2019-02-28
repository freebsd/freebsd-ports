# $FreeBSD$

PORTNAME=	git-absorb
DISTVERSION=	0.3.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	greg@unrelenting.technology
COMMENT=	Git command for automating fixup/autosquash commits

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	tummychow

CARGO_CRATES=	ansi_term-0.10.2 \
		atty-0.2.6 \
		backtrace-0.3.5 \
		backtrace-sys-0.1.16 \
		bitflags-1.0.1 \
		cc-1.0.25 \
		cfg-if-0.1.2 \
		chrono-0.4.0 \
		clap-2.30.0 \
		failure-0.1.1 \
		failure_derive-0.1.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		git2-0.7.5 \
		idna-0.1.4 \
		isatty-0.1.6 \
		kernel32-sys-0.2.2 \
		lazy_static-1.0.0 \
		libc-0.2.49 \
		libgit2-sys-0.7.10 \
		libz-sys-1.0.25 \
		log-0.4.6 \
		matches-0.1.6 \
		memchr-2.0.1 \
		num-0.1.42 \
		num-integer-0.1.36 \
		num-iter-0.1.35 \
		num-traits-0.2.0 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.9 \
		quote-0.3.15 \
		rand-0.4.2 \
		redox_syscall-0.1.37 \
		redox_termios-0.1.1 \
		remove_dir_all-0.3.0 \
		rustc-demangle-0.1.5 \
		slog-2.1.1 \
		slog-async-2.2.0 \
		slog-term-2.3.0 \
		strsim-0.7.0 \
		syn-0.11.11 \
		synom-0.11.3 \
		synstructure-0.6.1 \
		take_mut-0.2.0 \
		tempdir-0.3.6 \
		term-0.4.6 \
		termion-1.5.1 \
		textwrap-0.9.0 \
		thread_local-0.3.5 \
		time-0.1.39 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.5 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		unreachable-1.0.0 \
		url-1.6.0 \
		vcpkg-0.2.2 \
		vec_map-0.8.0 \
		void-1.0.2 \
		winapi-0.2.8 \
		winapi-0.3.4 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/git-absorb

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/git-absorb

.include <bsd.port.mk>
