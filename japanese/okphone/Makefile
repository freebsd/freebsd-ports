# New ports collection makefile for:	okphone
# Version required:	1.2
# Date created:		7 February 1996
# Whom:			asami
#
# $Id: Makefile,v 1.10 1997/12/25 22:29:40 asami Exp $
#

DISTNAME=	okphone-1.2
PKGNAME=	ja-okphone-1.2
CATEGORIES=	japanese net
MASTER_SITES=	ftp://ftp.kyushu-u.ac.jp/pub/utils/

PATCH_SITES=	ftp://ftp.fit.ac.jp/pub/Net/okphone/patch/
PATCHFILES=	okphone-1.2.FreeBSD-patch.rev2.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.ORG

post-install:
	@${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
