# New ports collection makefile for:	k12font
# Version required:	1.0
# Date created:		24 June 1996
# Whom:			Mita Yoshio <mita@jp.FreeBSD.org>
#
# $Id: Makefile,v 1.3 1997/07/13 18:49:17 max Exp $
#

DISTNAME=	kaname_k12_bdf
PKGNAME=	ja-k12font-1.0
CATEGORIES=	japanese x11
MASTER_SITES=	ftp://ftp.noc.titech.ac.jp/pub/tmp/aki/FreeBSD/etc/

MAINTAINER=	mita@jp.FreeBSD.org

USE_X11=	yes
NO_WRKSUBDIR=	yes

post-install:
	@${SH} ${PKGDIR}/REQ ${PKGNAME} INSTALL

.include <bsd.port.mk>
