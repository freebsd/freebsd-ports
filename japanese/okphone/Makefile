# New ports collection makefile for:	okphone
# Version required:	1.2
# Date created:		7 February 1996
# Whom:			asami
#
# $Id: Makefile,v 1.9 1997/09/14 21:35:36 max Exp $
#

DISTNAME=	okphone-1.2
PKGNAME=	ja-okphone-1.2
CATEGORIES=	japanese net
MASTER_SITES=	http://www.iij-mc.co.jp/odajima/okphone/src/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	okphone-1.2.FreeBSD-patch.rev2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.ORG

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
