# New ports collection makefile for:	ircd-hybrid
# Version required:	5.2p1
# Date created:		9 January 1998
# Whom:			desmo@bandwidth.org
#
# $Id: Makefile,v 1.3 1998/04/20 07:50:52 jkh Exp $
#

DISTNAME=	ircd-hybrid-5.2p1
PKGNAME=	ircd-hybrid-5.2.1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.vol.com/pub/ircd/

MAINTAINER=	desmo@bandwidth.org

GNU_CONFIGURE=	yes

MAN8=		ircd.8

pre-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${MANPREFIX}/man/man8
	#/bin/sh ${PKGDIR}/INSTALL

.include <bsd.port.mk>
