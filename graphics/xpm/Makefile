# New ports collection makefile for:	xpm
# Version required:	3.4e
# Date created:		14 September 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.6 1995/04/09 07:09:52 asami Exp $
#

DISTNAME=	xpm-3.4e
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://avahi.inria.fr/pub/xpm/

USE_IMAKE=	yes
XMKMF=		xmkmf

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
