# Ports collection makefile for:  dnsutl
# Date created:			  Nov 05, 1998
# Whom:				  Karl Dietz (Karl.Dietz@frankfurt.netsurf.de)
#
# $FreeBSD$
#

PORTNAME=	dnsutl
PORTVERSION=	1.6
CATEGORIES=	dns
MASTER_SITES=	http://www.canb.auug.org.au/~millerp/dnsutl/ \
		http://www.tip.net.au/~millerp/dnsutl/  \
		http://gd.tuwien.ac.at/softeng/Aegis/dnsutl/ \
		ftp://ftp.agso.gov.au/pub/Aegis/dnsutl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Programs to make using DNS easier

GNU_CONFIGURE=	yes
ALL_TARGET=	all sure

MAN1=		dns-boot-check.1 dns-bootp.1 dns-bootparams.1 \
		dns-ethers-import.1 dns-ethers.1 dns-filter.1 \
		dns-hosts-import.1 dns-hosts.1 dns-license.1 \
		dns-ng.1 dns-rev.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 501000
BROKEN=		"Does not build"
.endif

.include <bsd.port.post.mk>
