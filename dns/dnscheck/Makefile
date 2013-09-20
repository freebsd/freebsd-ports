# Created by: Jarrod Sayers <jarrod@netleader.com.au>
# $FreeBSD$

PORTNAME=	dnscheck
PORTVERSION=	1.3
CATEGORIES=	dns
MASTER_SITES=	http://www.downtools.com.au/~jarrod/projects/dnscheck/download/

MAINTAINER=	jarrod@downtools.com.au
COMMENT=	DNS zone sanity checker

USES=		perl5

PLIST_FILES=	bin/dnscheck

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e 's|^#!/usr/bin/perl |#!${PERL} |' ${WRKSRC}/dnscheck.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dnscheck.pl ${PREFIX}/bin/dnscheck

.include <bsd.port.mk>
