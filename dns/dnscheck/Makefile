# New ports collection makefile for:	dnscheck
# Date created:				25 September 2005
# Whom:					Jarrod Sayers <jarrod@netleader.com.au>
#
# $FreeBSD$
#

PORTNAME=	dnscheck
PORTVERSION=	1.2
CATEGORIES=	dns
MASTER_SITES=	http://www.netleader.com.au/projects/dnscheck/download/

MAINTAINER=	jarrod@netleader.com.au
COMMENT=	DNS zone sanity checker

USE_PERL=	yes

PLIST_FILES=	bin/dnscheck

post-patch:
	${REINPLACE_CMD} -e 's|^#!/usr/bin/perl |#!${PERL} |' ${WRKSRC}/dnscheck.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dnscheck.pl ${PREFIX}/bin/dnscheck

.include <bsd.port.mk>
