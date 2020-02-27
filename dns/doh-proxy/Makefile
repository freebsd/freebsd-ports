# Created by: Timothy Beyer <beyert@cs.ucr.edu>
# $FreeBSD$

PORTNAME=	doh-proxy
DISTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	dns

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS-over-HTTP server proxy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	jedisct1
GH_PROJECT=	rust-doh

PLIST_FILES=	bin/doh-proxy

# make cargo-crates > Makefile.crates
.include "Makefile.crates"

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/doh-proxy

.include <bsd.port.mk>
