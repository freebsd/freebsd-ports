# New ports collection makefile for:	xv
# Version required:	3.10a
# Date created:		30 October 1994
# Whom:			smace
#
# $Id: Makefile,v 1.8 1995/05/13 23:57:44 asami Exp $
#

DISTNAME=	xv-3.10a
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.cis.upenn.edu/pub/xv/

LIB_DEPENDS=    jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg \
		tiff\\.3\\.:${PORTSDIR}/graphics/tiff

USE_IMAKE=	yes

# Restrictive copyright
NO_PACKAGE=	yes

.include <bsd.port.mk>
