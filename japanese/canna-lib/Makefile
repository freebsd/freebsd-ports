# New ports collection makefile for:	Canna
# Version required:	3.2p2
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#			NIIMI Satoshi <sa2c@and.or.jp>
#
# $Id: Makefile,v 1.4 1995/04/07 05:47:57 asami Exp $
#

DISTNAME=	Canna32p2
PKGNAME=	Canna-3.2.2
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/packages/Canna32/ \
		ftp://ftp.cdrom.com/pub/japanese/titech/Canna32/

MAINTAINER=	asami@FreeBSD.ORG

PATCH_STRIP=	-p1
ALL_TARGET=	canna

pre-configure:
	@(cd ${WRKSRC}; ${XMKMF})

.include <bsd.port.mk>
