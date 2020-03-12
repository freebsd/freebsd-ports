# $FreeBSD$

PORTNAME=	interactive_rebase_tool
DISTVERSION=	1.2.1
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	petteri.valkonen@iki.fi
COMMENT=	Improved sequence editor for Git

LICENSE=	GPLv3+

LIB_DEPENDS=	libgit2.so:devel/libgit2

USES=		cargo ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	MitMaro
GH_PROJECT=	git-interactive-rebase-tool

CARGO_CRATES=	ansi_term-0.11.0 \
		atty-0.2.11 \
		bitflags-1.0.4 \
		cc-1.0.29 \
		cfg-if-0.1.6 \
		chrono-0.4.6 \
		clap-2.32.0 \
		git2-0.7.5 \
		idna-0.1.5 \
		libc-0.2.49 \
		libgit2-sys-0.7.11 \
		libz-sys-1.0.25 \
		log-0.4.6 \
		matches-0.1.8 \
		ncurses-5.98.0 \
		num-integer-0.1.39 \
		num-traits-0.2.6 \
		pancurses-0.16.1 \
		pdcurses-sys-0.7.0 \
		percent-encoding-1.0.1 \
		pkg-config-0.3.14 \
		redox_syscall-0.1.51 \
		redox_termios-0.1.1 \
		smallvec-0.6.8 \
		strsim-0.7.0 \
		termion-1.5.1 \
		textwrap-0.10.0 \
		time-0.1.42 \
		unicode-bidi-0.3.4 \
		unicode-normalization-0.1.8 \
		unicode-segmentation-1.2.1 \
		unicode-width-0.1.5 \
		unreachable-1.0.0 \
		url-1.7.2 \
		vcpkg-0.2.6 \
		vec_map-0.8.1 \
		void-1.0.2 \
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
