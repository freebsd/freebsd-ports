# New ports collection makefile for:	Canna
# Version required:	3.2p1
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi
#
# $Id: Makefile,v 1.2 1995/03/24 11:09:21 asami Exp $
#

DISTNAME=	Canna32p1
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/packages/Canna32/
CATEGORIES+=	japanese
MAINTAINER=	asami@FreeBSD.ORG
PATCH_STRIP=	-p1
ALL_TARGET=	canna

pre-configure:
	@(cd ${WRKSRC}; ${XMKMF})

.include <bsd.port.mk>
