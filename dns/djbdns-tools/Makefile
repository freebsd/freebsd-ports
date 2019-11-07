# Created by: Sergei Kolobov <sergei@FreeBSD.org>
# $FreeBSD$

PORTNAME=	djbdns
PORTVERSION=	1.05
CATEGORIES=	dns
MASTER_SITES=	http://cr.yp.to/djbdns/ \
		ftp://cr.yp.to/djbdns/ \
		http://smarden.org/pape/djb/manpages/:manpages
PKGNAMESUFFIX=	-tools
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DISTNAME}-man-20031023.tar.gz:manpages

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Resolver tools from djbdns package

CONFLICTS=	djbdns-[0-9]*

PROGRAMS=	dnsip dnsipq dnsname dnstxt dnsmx dnsfilter \
		random-ip dnsqr dnsq dnstrace
SCRIPTS=	dnstracesort

MANPAGES=	dnsfilter.1 dnsip.1 dnsipq.1 dnsmx.1 dnsname.1 \
		dnsq.1 dnsqr.1 dnstrace.1 dnstracesort.1 dnstxt.1

ALL_TARGET=	it

do-configure:
	@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
	@${ECHO_CMD} "${CC} ${STRIP}" > ${WRKSRC}/conf-ld
	@${ECHO_CMD} "${PREFIX}" > ${WRKSRC}/conf-home

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC} && \
	${INSTALL_PROGRAM} ${PROGRAMS} ${STAGEDIR}${PREFIX}/bin && \
	${INSTALL_SCRIPT} ${SCRIPTS} ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKDIR}/djbdns-man && \
	${INSTALL_MAN} ${MANPAGES} ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
