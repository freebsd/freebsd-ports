# New ports collection makefile for:	nkf
# Version required:	1.5 pl 1
# Date created:		5 February 1995
# Whom:			asami
#
# $Id: Makefile,v 1.4 1994/11/25 18:20:48 asami Exp $
#

DISTNAME=	nkf-1.5pl1
MASTER_SITES=	ftp://www.hitachi-sk.co.jp/pub/Japanese/filter/

pre-patch: ${PATCH_COOKIE}
	@echo "===>  Installing custom Makefile for ${DISTNAME}"
	@(cp ${FILESDIR}/Makefile ${WRKSRC})

.include <bsd.port.mk>
