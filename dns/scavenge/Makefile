# New ports collection makefile for:	scavenge
# Date created:		13 April 2005
# Whom:			mark@foster.cc
#
# $FreeBSD$

PORTNAME=	scavenge
PORTVERSION=	1.3
CATEGORIES=	dns
MASTER_SITES=	http://mark.foster.cc/pub/scavenge/

MAINTAINER=	mark@foster.cc
COMMENT=	Discover/audit forward and reverse DNS records

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS \
		nmap:${PORTSDIR}/security/nmap

PLIST_FILES=	bin/scavenge

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/scavenge ${PREFIX}/bin

.include <bsd.port.mk>
