# New ports collection makefile for:	xpm
# Version required:     3.4j
# Date created:		14 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.12 1997/01/10 03:35:50 ache Exp $
#

DISTNAME=       xpm-3.4j
CATEGORIES=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

USE_IMAKE=	yes

post-install:
	/sbin/ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
