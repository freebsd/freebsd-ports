# New ports collection makefile for:	h2n
# Date created:		27 Nov 1997
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	h2n
PORTVERSION=	1.29
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.oreilly.com/published/oreilly/nutshell/dnsbind/
DISTNAME=	dns.3ed
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate host table to name server file format

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
RESTRICTED=	Never got an approval yet.

PLIST_FILES=	bin/h2n man/cat8/h2n.8

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/h2n ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/h2n.man ${PREFIX}/man/cat8/h2n.8

.include <bsd.port.mk>
