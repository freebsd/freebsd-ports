# New ports collection makefile for:    xasteroids
# Version required:	5
# Date created:         3 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.7 1997/01/03 09:36:55 obrien Exp $
#

DISTNAME=       xasteroids
PKGNAME=	xasteroids-5.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/
EXTRACT_SUFX=	.sh.Z

MAINTAINER=	swallace@FreeBSD.org

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	( cd ${WRKDIR}; zcat | sh -s )
EXTRACT_ARGS=	<

.include <bsd.port.mk>
