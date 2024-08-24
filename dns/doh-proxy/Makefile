PORTNAME=	doh-proxy
DISTVERSION=	0.9.8
PORTREVISION=	12
CATEGORIES=	dns
MASTER_SITES=	CRATESIO
DISTFILES=	${CARGO_DIST_SUBDIR}/${DISTNAME}${CARGO_CRATE_EXT}

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	DNS-over-HTTP server proxy
WWW=		https://github.com/DNSCrypt/doh-server

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_i386=	fails to build
USES=		cargo

PLIST_FILES=	bin/doh-proxy

# make cargo-crates > Makefile.crates

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/doh-proxy

.include <bsd.port.mk>
