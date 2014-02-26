# Created by: Jarrod Sayers <jarrod@netleader.com.au>
# $FreeBSD$

PORTNAME=	dnscheck
PORTVERSION=	1.3
CATEGORIES=	dns
MASTER_SITES=	http://www.downtools.com.au/~jarrod/projects/dnscheck/download/

MAINTAINER=	jarrod@downtools.com.au
COMMENT=	DNS zone sanity checker

USES=		perl5 shebangfix

PLIST_FILES=	bin/dnscheck
SHEBANG_FILES=	dnscheck.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dnscheck.pl \
		${STAGEDIR}${PREFIX}/bin/dnscheck

.include <bsd.port.mk>
