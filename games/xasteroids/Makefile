# New ports collection makefile for:    xasteroids
# Version required:	5
# Date created:         3 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.10 1998/10/03 13:39:44 jseger Exp $
#

DISTNAME=       xasteroids
PKGNAME=	xasteroids-5.0
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.cdrom.com/pub/X11/R5contrib/ \
		ftp://ftp.belgium.eu.net/pub/X11/R5contrib/
EXTRACT_SUFX=	.sh.Z

MAINTAINER=	swallace@FreeBSD.org

USE_IMAKE=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	( cd ${WRKDIR}; zcat | sh -s )
EXTRACT_BEFORE_ARGS=	<
EXTRACT_AFTER_ARGS=	# empty
MAN6=		xasteroids.6

.include <bsd.port.mk>
