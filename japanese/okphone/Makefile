# New ports collection makefile for:	okphone
# Version required:	1.2
# Date created:		7 February 1996
# Whom:			asami
#
# $Id: Makefile,v 1.6 1997/01/24 19:09:11 max Exp $
#

DISTNAME=	okphone-1.2
PKGNAME=	jp-okphone-1.2
CATEGORIES=	japanese net
MASTER_SITES=	http://www.iij-mc.co.jp/odajima/okphone/src/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	okphone-1.2.FreeBSD-patch.rev2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	asami@FreeBSD.ORG

post-install:
	@/bin/sh ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
