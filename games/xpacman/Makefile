# New ports collection makefile for:    xpacman
# Version required:     1.0
# Date created:         19 Aug 1995
# Whom:                 joerg
#
# $Id$
#

DISTNAME=       pacman10
EXTRACT_SUFX=	.zip
PKGNAME=	xpacman-1.0
CATEGORIES+=	games
MASTER_SITES=	ftp://ftp.nvg.unit.no/pub/pacman/
MAINTAINER=	joerg@FreeBSD.org

NO_WRKSUBDIR=	Does not unpack into subdir.
EXEC_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS= -x

USE_IMAKE=      yes

.include <bsd.port.mk>
