PORTNAME=	doh-proxy
DISTVERSION=	0.9.12
PORTREVISION=	1
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

USE_RC_SUBR=	doh-proxy

PLIST_FILES=	bin/doh-proxy

# make cargo-crates > Makefile.crates

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
LIB_DEPENDS+=	libatomic.so:lang/gcc${GCC_DEFAULT}
LDFLAGS+=	-L/usr/local/lib/gcc${GCC_DEFAULT} -latomic
.endif

.include <bsd.port.mk>
