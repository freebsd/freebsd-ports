PORTNAME=	dnsreflector
PORTVERSION=	1.02
CATEGORIES=	dns
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	ismail.yenigul@endersys.com.tr
COMMENT=	Listens for DNS queries on a UDP port and change the answer

USE_RC_SUBR=	dnsreflector

PORTDOCS=	README
PLIST_FILES=	sbin/dnsreflector man/man1/dnsreflector.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnsreflector ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsreflector.1 ${STAGEDIR}${MANPREFIX}/man/man1/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
