# New ports collection makefile for:    xpacman
# Version required:     1.0
# Date created:         19 Aug 1995
# Whom:                 joerg
#
# $Id: Makefile,v 1.4 1996/11/18 11:26:27 asami Exp $
#

DISTNAME=       pacman10
PKGNAME=	xpacman-1.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.nvg.unit.no/pub/pacman/
EXTRACT_SUFX=	.zip

MAINTAINER=	joerg@FreeBSD.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	Does not unpack into subdir.
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS= -x
USE_IMAKE=      yes
MAN1=		pacman.1

.include <bsd.port.mk>
