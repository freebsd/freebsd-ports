# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	doh-proxy
DISTVERSION=	0.3.2
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	CRATESIO
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS-over-HTTP server proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

PLIST_FILES=	bin/doh-proxy

# make cargo-crates > Makefile.crates
.include "Makefile.crates"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/doh-proxy

.include <bsd.port.mk>
