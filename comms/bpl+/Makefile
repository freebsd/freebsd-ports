# New ports collection makefile for:	bpl+
# Version required:		?
# Date created:			22 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.ORG>
#
# $Id: porting.sgml,v 1.16 1996/03/21 14:15:01 asami Exp $
#

DISTNAME=	bpl+
PKGNAME=	bpl+
CATEGORIES+=	comms
MASTER_SITES=	ftp://ftp.tohoku.ac.jp/pub/net/telnet/telnetx/

MAINTAINER=	max@FreeBSD.ORG

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpl ${PREFIX}/bin
	@ln -fs ${PREFIX}/bin/bpl ${PREFIX}/bin/bp

.include <bsd.port.mk>
