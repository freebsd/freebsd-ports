# New ports collection makefile for: dnscache
# Date created:		24 Jan 2000
# Whom:			Neil Blakey-Milner
#
# $FreeBSD$
#

PORTNAME=	djbdns
PORTVERSION=	${DJBDNS_VER}
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/
DISTNAME=	${PORTNAME}-${DJBDNS_VER}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

.if !defined(WITHOUT_MAN)
MANDATE=	-20020130
MASTER_SITES+=	http://smarden.org/pape/djb/manpages/:1
DISTFILES+=	${DISTNAME}-man${MANDATE}.tar.gz:1

MAN1=		dnsfilter.1 dnsip.1 dnsipq.1 dnsmx.1 dnsname.1 \
		dnsq.1 dnsqr.1 dnstrace.1 dnstracesort.1 dnstxt.1
MAN8=		axfr-get.8 axfrdns.8 dnscache-conf.8 dnscache.8 \
		pickdns-conf.8 pickdns-data.8 pickdns.8 rbldns-conf.8 \
		rbldns-data.8 rbldns.8 tinydns-conf.8 tinydns-data.8 \
		tinydns-edit.8 tinydns.8 walldns-conf.8 walldns.8
MANCOMPRESSED=	no
.endif

.if defined(WITH_IPV6)
PKGNAMESUFFIX=	-ipv6
PORTVERSION=	${DJBDNS_VER}.${DJBDNS_V6_VER:S/test/b/:S/diff//}
PATCH_SITES=	http://www.fefe.de/dns/
PATCHFILES=	${PORTNAME}-${DJBDNS_VER}-${DJBDNS_V6_VER}.diff.bz2
PATCH_DIST_STRIP=	-p1
.endif

DJBDNS_VER=	1.05
DJBDNS_V6_VER=	test11

MAINTAINER=	roam@FreeBSD.org

RUN_DEPENDS=	setuidgid:${PORTSDIR}/sysutils/daemontools

ALL_TARGET=	it
INSTALL_TARGET=	setup check

NO_PACKAGE=	Forbidden - we have patches to the distribution.

.if defined(WITH_IPV6)
PLIST_SUB+=	WITH_IPV6=""
.else
PLIST_SUB+=	WITH_IPV6="@comment "
.endif

post-patch:
	@echo "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@echo "${CC} -s" > ${WRKSRC}/conf-ld
	@echo "${PREFIX}" > ${WRKSRC}/conf-home

.if !defined(WITHOUT_MAN)
post-install:
	@${INSTALL_MAN} ${WRKDIR}/djbdns-man/*.1 ${PREFIX}/man/man1/
	@${INSTALL_MAN} ${WRKDIR}/djbdns-man/*.8 ${PREFIX}/man/man8/
.endif

.include <bsd.port.mk>
