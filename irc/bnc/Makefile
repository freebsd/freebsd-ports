# New ports collection makefile for:   bnc
# Version required:    2.4.3
# Date created:        06 July 1998
# Whom:                Bill Fumerola <billf@chc-chimes.com>
#
# $Id: Makefile,v 1.3 1999/05/16 23:07:23 mharo Exp $
#

DISTNAME=	bnc2.6.2
PKGNAME=	bnc-2.6.2
CATEGORIES=	irc
MASTER_SITES=	http://irc.themes.org/downloads/misc/

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
