# New ports collection makefile for:    xlife
# Version required:     3.0
# Date created:         15 March 1995
# Whom:                 asami
#
# $FreeBSD$
#

DISTNAME=       xlife
PKGNAME=	xlife-3.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/ \
		ftp://ftp.kddlabs.co.jp/pub/X11/R5contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

USE_IMAKE=      yes
MAN1=		xlife.1

pre-install:
	@(cd ${WRKSRC}; make install.patterns)

.include <bsd.port.mk>
