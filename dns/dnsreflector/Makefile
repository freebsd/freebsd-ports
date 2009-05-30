# New ports collection makefile for:   dnsreflector
# Date created:        May 30 2009
# Whom:                ismail.yenigul@endersys.com.tr
#
# $FreeBSD$
#

PORTNAME=	dnsreflector
PORTVERSION=	1.02
CATEGORIES=	dns
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	ismail.yenigul@endersys.com.tr
COMMENT=	Listens for DNS queries on a UDP port and change the answer

USE_RC_SUBR=	dnsreflector

MAN1=		dnsreflector.1
PORTDOCS=	README

PLIST_FILES=	sbin/dnsreflector

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnsreflector ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsreflector.1 ${MANPREFIX}/man/man1/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
