# $FreeBSD$

PORTNAME=	interactive_rebase_tool
DISTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Improved sequence editor for Git

LICENSE=	ISCL

USES=		cargo ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	MitMaro
GH_PROJECT=	git-interactive-rebase-tool

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		cc-1.0.25 \
		cfg-if-0.1.6 \
		clap-2.32.0 \
		curl-sys-0.4.13 \
		git2-0.7.5 \
		idna-0.1.5 \
		libc-0.2.49 \
		libgit2-sys-0.7.10 \
		libssh2-sys-0.2.11 \
		libz-sys-1.0.25 \
		log-0.4.6 \
		matches-0.1.8 \
		ncurses-5.94.0 \
		openssl-probe-0.1.2 \
		openssl-sys-0.9.39 \
		pad-0.1.5 \
		pancurses-0.16.0 \
		pdcurses-sys-0.7.0 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		redox_syscall-0.1.40 \
		redox_termios-0.1.1 \
		strsim-0.7.0 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.7 \
		unicode-width-0.1.5 \
		url-1.7.1 \
		vcpkg-0.2.6 \
		vec_map-0.8.1 \
		winapi-0.3.6 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		winreg-0.5.1

PLIST_FILES=	bin/interactive-rebase-tool \
		man/man1/interactive-rebase-tool.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/interactive-rebase-tool
	${INSTALL_MAN} ${WRKSRC}/src/interactive-rebase-tool.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
