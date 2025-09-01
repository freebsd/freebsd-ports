PORTNAME=	cargo-bloat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.12.1
PORTREVISION=	12
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Rust: Find out what takes most of the space in your executable
WWW=		https://github.com/RazrFalcon/cargo-bloat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	RazrFalcon

CARGO_CRATES=	aho-corasick-1.1.3 \
		binfarce-0.2.1 \
		fallible-iterator-0.2.0 \
		json-0.12.4 \
		libc-0.2.154 \
		memchr-2.7.2 \
		memmap2-0.9.4 \
		multimap-0.10.0 \
		pdb-0.8.0 \
		pico-args-0.5.0 \
		regex-1.10.4 \
		regex-automata-0.4.6 \
		regex-syntax-0.8.3 \
		scroll-0.11.0 \
		term_size-0.3.2 \
		uuid-1.8.0 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
