# New ports collection makefile for:    xasteroids
# Date created:         3 Jan 1995
# Whom:                 swallace
#
# $Id: Makefile,v 1.3 1995/02/11 13:49:06 asami Exp $
#

DISTNAME=       xasteroids
MASTER_SITES=	ftp://calypso-2.oit.unc.edu/pub/X11/contrib/
CATEGORIES+=	games
EXTRACT_SUFX=	.sh.Z
EXTRACT_CMD=	( cd ${WRKDIR}; zcat | sh -s )
EXTRACT_ARGS= <
USE_IMAKE=	yes
NO_WRKSUBDIR=	yes

.include <bsd.port.mk>
