# New ports collection makefile for:    ncftp
# Version required:     1.9.5
# Date created:         20 Jun 1996
# Whom:                 jkh
#
# $Id: Makefile,v 1.8 1998/01/31 17:49:32 jseger Exp $
#

DISTNAME=       ncftp-1.9.5
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.ncftp.com/ncftp/

MAINTAINER=	obrien@FreeBSD.org

NO_LATEST_LINK=	yes
MAN1=		ncftp.1

do-install:
	cd ${WRKSRC}; ${INSTALL_PROGRAM} ncftp ${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_MAN} ncftp.1 ${PREFIX}/man/man1

.include <bsd.port.mk>
