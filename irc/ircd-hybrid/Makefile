# New ports collection makefile for:	ircd-hybrid
# Version required:	5
# Date created:		9 January 1998
# Whom:			desmo@bandwidth.org
#
# $Id: Makefile,v 1.1.1.1 1998/01/15 06:44:49 jkh Exp $
#

DISTNAME=	ircd-hybrid-5
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.vol.com/pub/ircd/

MAINTAINER=	desmo@bandwidth.org

GNU_CONFIGURE=	yes
IS_INTERACTIVE=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/ircd.8 ${MANPREFIX}/man/man8
	/bin/sh ${PKGDIR}/INSTALL

.include <bsd.port.mk>
