# New ports collection makefile for:	okphone
# Version required:	1.2
# Date created:		7 February 1996
# Whom:			asami
#
# $Id: Makefile,v 1.1.1.1 1996/02/08 04:54:18 asami Exp $
#

DISTNAME=	okphone-1.2
PKGNAME=	jp-okphone-1.2
CATEGORIES+=	japanese net
MASTER_SITES=	ftp://www.iijnet.or.jp/IIJ-MC/odajima/okphone/src/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	okphone-1.2.FreeBSD-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	asami@FreeBSD.ORG

post-install:
	@${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
