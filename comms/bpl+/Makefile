# New ports collection makefile for:	bpl+
# Version required:		?
# Date created:			22 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: Makefile,v 1.1.1.1 1996/09/25 20:28:43 max Exp $
#

DISTNAME=	bpl+
PKGNAME=	bpl+-1.0
CATEGORIES+=	comms
MASTER_SITES=	ftp://ftp.tohoku.ac.jp/pub/net/telnet/telnetx/

MAINTAINER=	max@FreeBSD.ORG

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpl ${PREFIX}/bin
	@ln -fs ${PREFIX}/bin/bpl ${PREFIX}/bin/bp

.include <bsd.port.mk>
