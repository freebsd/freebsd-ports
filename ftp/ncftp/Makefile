# New ports collection makefile for:    ncftp2
# Version required:     1.9.5
# Date created:         20 Jun 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.5 1997/01/06 12:12:08 jkh Exp $
#

DISTNAME=       ncftp-1.9.5
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.probe.net/pub/ncftp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	obrien@FreeBSD.org

MAN1=		ncftp.1

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ncftp ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_MAN} ncftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
