# New ports collection makefile for:    ncftp2
# Version required:     1.9.5
# Date created:         20 Jun 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.4 1996/12/01 01:23:00 obrien Exp $
#

DISTNAME=       ncftp-1.9.5
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.probe.net/pub/ncftp/
EXTRACT_SUFX=	.tgz

MAN1=		ncftp.1

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ncftp ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_MAN} ncftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
