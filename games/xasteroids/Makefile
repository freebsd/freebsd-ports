# New ports collection makefile for:    xasteroids
# Version required:	5
# Date created:         3 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.6 1996/11/18 11:25:16 asami Exp $
#

DISTNAME=       xasteroids
PKGNAME=	xasteroids-5.0
CATEGORIES=	games
MASTER_SITES=	ftp://calypso-2.oit.unc.edu/pub/X11/contrib/
EXTRACT_SUFX=	.sh.Z

MAINTAINER=	swallace@FreeBSD.org

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	( cd ${WRKDIR}; zcat | sh -s )
EXTRACT_ARGS=	<

.include <bsd.port.mk>
