# New ports collection makefile for:	tgif-j
# Version required:	2.16.12
# Date created:		8 Dec 1995
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.1.1.1 1996/02/01 06:47:41 asami Exp $
#

DISTNAME=	tgif-2.16-p12
PKGNAME=	jp-tgif-216-p12
CATEGORIES+=	japanese
MASTER_SITES=	ftp://theta.iis.u-tokyo.ac.jp/pub1/X/contrib/applications/tgif/

PATCH_SITES=	ftp://ftp.eos.hokudai.ac.jp/pub/X/contrib/misc/tgif/
PATCHFILES=	tgif-2.16-p12.jp.gz \
		tgif-2.16-p12.jp.kinput2over-the-spotpatch
PATCH_DIST_STRIP=	-p1

MAINTAINER=	mita@jp.FreeBSD.org

USE_IMAKE=	yes

.include <bsd.port.mk>
