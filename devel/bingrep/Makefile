# $FreeBSD$

PORTNAME=	bingrep
PORTVERSION=	g20170612
CATEGORIES=	devel

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Grep through binaries

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	m4b
GH_TAGNAME=	0705684

PLIST_FILES=	bin/bingrep

CARGO_CRATES=	ansi_term-0.9.0 \
		atty-0.2.2 \
		bitflags-0.8.2 \
		clap-2.24.2 \
		colored-1.5.1 \
		goblin-0.0.10 \
		kernel32-sys-0.2.2 \
		lazy_static-0.2.8 \
		libc-0.2.23 \
		plain-0.0.2 \
		quote-0.3.15 \
		scroll-0.5.0 \
		scroll_derive-0.4.0 \
		strsim-0.6.0 \
		structopt-0.0.3 \
		structopt-derive-0.0.3 \
		syn-0.11.11 \
		synom-0.11.3 \
		term_size-0.3.0 \
		unicode-segmentation-1.2.0 \
		unicode-width-0.1.4 \
		unicode-xid-0.0.4 \
		vec_map-0.8.0 \
		winapi-0.2.8 \
		winapi-build-0.1.1

.include <bsd.port.mk>
