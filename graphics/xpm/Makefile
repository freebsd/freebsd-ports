# New ports collection makefile for:	xpm
# Version required:	3.4f
# Date created:		14 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.7 1995/06/24 11:38:29 asami Exp $
#

DISTNAME=	xpm-3.4f
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

USE_IMAKE=	yes
XMKMF=		xmkmf

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
