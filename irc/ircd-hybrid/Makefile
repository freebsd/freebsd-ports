# New ports collection makefile for:	ircd-hybrid
# Version required:	5.3
# Date created:		9 January 1998
# Whom:			desmo@bandwidth.org
#
# $Id: Makefile,v 1.5 1998/06/07 15:58:19 dburr Exp $
#

DISTNAME=	ircd-hybrid-5.3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.vol.com/pub/ircd/

MAINTAINER=	desmo@bandwidth.org

GNU_CONFIGURE=	yes

MAN8=		ircd.8

pre-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${MANPREFIX}/man/man8
	${INSTALL_SCRIPT} ${FILESDIR}/ircd.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA} ${WRKSRC}/doc/example.conf.trillian ${PREFIX}/etc/ircd

.include <bsd.port.mk>
