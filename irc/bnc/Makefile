# New ports collection makefile for:   bnc
# Date created:        06 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $FreeBSD$
#

PORTNAME=	bnc
PORTVERSION=	2.8.2
CATEGORIES=	irc
MASTER_SITES=	http://www.psn.net/~andrews/dist/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	billf@FreeBSD.org

GNU_CONFIGURE=	YES

post-patch:
	${SED} 's,@PREFIX@,${PREFIX},g' ${WRKSRC}/bncsetup > ${WRKSRC}/bncsetup.new
	${MV} ${WRKSRC}/bncsetup.new ${WRKSRC}/bncsetup

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bnc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bncchk ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bncsetup ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/mkpasswd ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/example.conf ${PREFIX}/etc/bnc.conf.sample

.include <bsd.port.mk>
