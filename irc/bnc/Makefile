# New ports collection makefile for:   bnc
# Version required:    2.4.3
# Date created:        06 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id$
#

DISTNAME=	bnc-web
PKGNAME=	bnc-2.4.3
CATEGORIES=	net
MASTER_SITES=	http://www.bridgenet.net/bnc/

MAINTAINER=	billf@chc-chimes.com

WRKSRC=		${WRKDIR}/bnc2.4.3
HAS_CONFIGURE=	YES
GNU_CONFIGURE=	YES

do-install:
	${CP} ${WRKSRC}/bnc ${PREFIX}/bin
	${CP} ${WRKSRC}/bncchk ${PREFIX}/bin
	${CP} ${WRKSRC}/example.conf ${PREFIX}/etc/bnc.conf

.include <bsd.port.mk>
