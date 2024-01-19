PORTNAME=	gen6dns
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://www.hznet.de/tools/

MAINTAINER=	se@FreeBSD.org
COMMENT=	Tool to generate static DNS records for IPv6 hosts using SLAAC
WWW=		https://www.hznet.de/tools.html

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/gen6dns bin/soaserial ${PREFIX}/share/man/man1/gen6dns.1.gz

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/gen6dns ${STAGEDIR}${PREFIX}/bin
		${INSTALL_PROGRAM} ${WRKSRC}/soaserial ${STAGEDIR}${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/gen6dns.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
