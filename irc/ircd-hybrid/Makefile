# New ports collection makefile for:	ircd-hybrid
# Version required:	5.3p4
# Date created:		9 January 1998
# Whom:			desmo@bandwidth.org
#
# $Id: Makefile,v 1.8 1998/11/16 21:44:58 billf Exp $
#

DISTNAME=	ircd-hybrid-5.3p4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.blackened.com/pub/irc/hybrid/

MAINTAINER=	desmo@bandwidth.org

GNU_CONFIGURE=	yes

MAN8=		ircd.8

pre-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/buildm4 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/fixklines ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/mkpasswd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/viconf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${MANPREFIX}/man/man8
	${INSTALL_SCRIPT} ${FILESDIR}/ircd.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf.trillian ${PREFIX}/etc/ircd

.include <bsd.port.mk>
