# New ports collection makefile for:    xasteroids
# Date created:         3 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.3 1994/12/31 04:17:52 swallace Exp $
#

DISTNAME=       xasteroids
MASTER_SITES=	ftp://calypso-2.oit.unc.edu/pub/X11/contrib/
EXTRACT_SUFX=	.sh.Z
EXTRACT_CMD=	cd ${WRKDIR}; zcat ${DISTDIR}/xasteroids.sh.Z | sh -s
EXTRACT_ARGS=
USE_IMAKE=	yes
INSTALL_MANPAGES= yes
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
