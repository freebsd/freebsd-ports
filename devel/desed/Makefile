PORTNAME=	desed
DISTVERSION=	1.2.0
PORTREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Demystify and debug sed scripts from the comfort of your terminal

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	gsed:textproc/gsed

USES=		cargo

PLIST_FILES=	bin/${PORTNAME}

CARGO_CRATES=	ansi_term-0.11.0 \
		anyhow-1.0.32 \
		arc-swap-0.4.7 \
		atty-0.2.14 \
		bitflags-1.2.1 \
		bytes-0.5.6 \
		cassowary-0.3.0 \
		cfg-if-0.1.10 \
		clap-2.33.3 \
		cloudabi-0.0.3 \
		crossterm-0.17.6 \
		crossterm_winapi-0.6.1 \
		either-1.6.1 \
		fuchsia-zircon-0.3.3 \
		fuchsia-zircon-sys-0.3.3 \
		futures-core-0.3.5 \
		hermit-abi-0.1.15 \
		inotify-0.8.3 \
		inotify-sys-0.1.3 \
		iovec-0.1.4 \
		itertools-0.9.0 \
		kernel32-sys-0.2.2 \
		kqueue-1.0.2 \
		kqueue-sys-1.0.1 \
		lazy_static-1.4.0 \
		libc-0.2.78 \
		lock_api-0.3.4 \
		log-0.4.8 \
		mio-0.6.22 \
		mio-0.7.0 \
		miow-0.2.1 \
		miow-0.3.5 \
		net2-0.2.35 \
		ntapi-0.3.4 \
		parking_lot-0.10.2 \
		parking_lot_core-0.7.2 \
		pin-project-lite-0.1.10 \
		redox_syscall-0.1.57 \
		scopeguard-1.1.0 \
		signal-hook-0.1.16 \
		signal-hook-registry-1.2.0 \
		slab-0.4.2 \
		smallvec-1.4.1 \
		socket2-0.3.12 \
		strsim-0.8.0 \
		textwrap-0.11.0 \
		tokio-0.2.22 \
		tui-0.9.5 \
		unicode-segmentation-1.6.0 \
		unicode-width-0.1.8 \
		vec_map-0.8.2 \
		winapi-0.2.8 \
		winapi-0.3.9 \
		winapi-build-0.1.1 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0 \
		ws2_32-sys-0.2.1

.include <bsd.port.mk>
