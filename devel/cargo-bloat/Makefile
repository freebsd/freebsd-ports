PORTNAME=	cargo-bloat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.1
PORTREVISION=	8
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Find out what takes most of the space in your executable
WWW=		https://github.com/RazrFalcon/cargo-bloat

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	RazrFalcon

CARGO_CRATES=	binfarce-0.2.1 \
		fallible-iterator-0.2.0 \
		json-0.12.4 \
		libc-0.2.126 \
		memmap2-0.5.4 \
		multimap-0.8.3 \
		pdb-0.7.0 \
		pico-args-0.5.0 \
		regex-1.5.6 \
		regex-syntax-0.6.26 \
		scroll-0.10.2 \
		term_size-0.3.2 \
		uuid-0.8.2 \
		winapi-0.3.9 \
		winapi-i686-pc-windows-gnu-0.4.0 \
		winapi-x86_64-pc-windows-gnu-0.4.0

PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
