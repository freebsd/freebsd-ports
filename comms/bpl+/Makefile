# New ports collection makefile for:	bpl+
# Version required:		?
# Date created:			22 Sep 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	bpl+
PKGNAME=	bpl+-1.0
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.tohoku.ac.jp/pub/net/telnet/telnetx/

MAINTAINER=	max@FreeBSD.org

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bpl ${PREFIX}/bin
	@${LN} -fs ${PREFIX}/bin/bpl ${PREFIX}/bin/bp

.include <bsd.port.mk>
