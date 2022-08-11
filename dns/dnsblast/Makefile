PORTNAME=	dnsblast
PORTVERSION=	0.0.2016060901
CATEGORIES=	dns benchmarks

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Simple load testing tool for DNS resolvers

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes

GH_ACCOUNT=	jedisct1
GH_TAGNAME=	f74cc52

PLIST_FILES=	bin/dnsblast

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
