# New ports collection makefile for:	h2n
# Date created:		27 Nov 1997
# Whom:			SADA Kenji <sada@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	h2n
PORTVERSION=	1.29
CATEGORIES=	dns
MASTER_SITES=	ftp://ftp.iij.ad.jp/pub/published/oreilly/nutshell/dnsbind/
DISTNAME=	dns
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Translate host table to name server file format

NO_BUILD=	YES
NO_WRKSUBDIR=	YES
RESTRICTED=	"Never get an approval yet."

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/h2n ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/h2n.man ${PREFIX}/man/cat8/h2n.8

.include <bsd.port.mk>
