# New ports collection makefile for:	Canna
# Version required:	3.2p1
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $Id: Makefile,v 1.3 1995/04/01 12:46:20 jkh Exp $
#

DISTNAME=	Canna32p1
PKGNAME=	Canna-3.2.1
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/packages/Canna32/ \
		ftp://ftp.cdrom.com/pub/japanese/titech/Canna32/

MAINTAINER=	asami@FreeBSD.ORG

PATCH_STRIP=	-p1
ALL_TARGET=	canna

pre-configure:
	@(cd ${WRKSRC}; ${XMKMF})

.include <bsd.port.mk>
