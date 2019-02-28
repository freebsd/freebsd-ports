# $FreeBSD$

PORTNAME=	xi-core
PORTVERSION=	g20170612
DISTVERSIONPREFIX=	v
PORTREVISION=	8
CATEGORIES=	editors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Modern editor backend written in Rust

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_PROJECT=	xi-editor
GH_TAGNAME=	3164cb6

WRKSRC_SUBDIR=	rust

PLIST_FILES=	bin/xi-core

CARGO_CRATES=	bytecount-0.1.6 \
		crossbeam-0.2.10 \
		dtoa-0.4.1 \
		itoa-0.3.1 \
		kernel32-sys-0.2.2 \
		libc-0.2.49 \
		memchr-1.0.1 \
		num-traits-0.1.37 \
		quote-0.3.15 \
		redox_syscall-0.1.17 \
		serde-1.0.2 \
		serde_derive-1.0.2 \
		serde_derive_internals-0.15.0 \
		serde_json-1.0.1 \
		syn-0.11.11 \
		synom-0.11.3 \
		time-0.1.37 \
		unicode-xid-0.0.4 \
		winapi-0.2.8 \
		winapi-build-0.1.1

.include <bsd.port.mk>
