# New ports collection makefile for:    xlife
# Version required:     3.0
# Date created:         15 March 1995
# Whom:                 asami
#
# $Id: Makefile,v 1.7 1997/09/09 02:52:07 asami Exp $
#

DISTNAME=       xlife
PKGNAME=	xlife-3.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/	\
		ftp://ftp.iij.ad.jp/X/R5contrib/
MASTER_SITE_SUBDIR=	../../R5contrib
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.ORG

USE_IMAKE=      yes

pre-install:
	@(cd ${WRKSRC}; make install.patterns)

.include <bsd.port.mk>
