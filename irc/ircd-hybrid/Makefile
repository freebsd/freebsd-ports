# New ports collection makefile for:	ircd-hybrid
# Date created:		9 January 1998
# Whom:			desmo@bandwidth.org
#
# $FreeBSD$
#

PORTNAME=	ircd-hybrid
PORTVERSION=	5.3p8
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.blackened.com/pub/irc/hybrid/ ftp://ftp.blackened.com/pub/irc/hybrid/old/

MAINTAINER=	desmo@bandwidth.org

GNU_CONFIGURE=	yes
IS_INTERACTIVE=	yes

MAN8=		ircd.8

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/buildm4 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/fixklines ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/ircd-mkpasswd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/viconf ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${MANPREFIX}/man/man8
	${INSTALL_SCRIPT} ${FILESDIR}/ircd.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf.trillian ${PREFIX}/etc/ircd

.include <bsd.port.mk>
