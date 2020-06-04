# $FreeBSD$

PORTNAME=	desed
DISTVERSION=	1.1.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Demystify and debug sed scripts from the comfort of your terminal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gsed:textproc/gsed

USES=		cargo

PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	ansi_term-0.11.0 \
		arc-swap-0.4.5 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		cassowary-0.3.0 \
		cfg-if-0.1.10 \
		clap-2.33.0 \
		cloudabi-0.0.3 \
		crossterm-0.17.3 \
		crossterm_winapi-0.6.1 \
		either-1.5.3 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		hermit-abi-0.1.11 \
		iovec-0.1.4 \
		itertools-0.9.0 \
		kernel32-sys-0.2.2 \
		lazy_static-1.4.0 \
		libc-0.2.69 \
		lock_api-0.3.4 \
		log-0.4.8 \
		mio-0.6.21 \
		miow-0.2.1 \
		net2-0.2.33 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.1 \
		redox_syscall-0.1.56 \
		scopeguard-1.1.0 \
		signal-hook-0.1.13 \
		signal-hook-registry-1.2.0 \
		slab-0.4.2 \
		smallvec-1.3.0 \
		strsim-0.8.0 \
		textwrap-0.11.0 \
		tui-0.9.1 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.7 \
		vec_map-0.8.1 \
		winapi-0.2.8 \
		winapi-0.3.8 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

.include <bsd.port.mk>
