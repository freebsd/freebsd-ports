# New ports collection makefile for:	Canna
# Version required:	3.2p1
# Date created:		3 November 1995
# Whom:			Nobuhiro Yasutomi
#
# $Id:$
#

DISTNAME=	Canna32p1
MASTER_SITES=	ftp://ftp.nec.co.jp/pub/packages/Canna32/
PATCH_STRIP=	-p1
ALL_TARGET=	canna

pre-configure:
	@(cd ${WRKSRC}; ${XMKMF})

.include <bsd.port.mk>
