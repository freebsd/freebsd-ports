# New ports collection makefile for:   bnc
# Version required:    2.4.3
# Date created:        06 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.1.1.1 1998/07/11 18:32:05 steve Exp $
#

DISTNAME=	bnc-web
PKGNAME=	bnc-2.4.3
CATEGORIES=	net
MASTER_SITES=	http://www.bridgenet.net/bnc/

MAINTAINER=	billf@FreeBSD.org

WRKSRC=		${WRKDIR}/bnc2.4.3
HAS_CONFIGURE=	YES
GNU_CONFIGURE=	YES

do-install:
	${CP} ${WRKSRC}/bnc ${PREFIX}/bin
	${CP} ${WRKSRC}/bncchk ${PREFIX}/bin
	${CP} ${WRKSRC}/example.conf ${PREFIX}/etc/bnc.conf

.include <bsd.port.mk>
