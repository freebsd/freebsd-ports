# New ports collection makefile for:	itcl
# Version required:	1.5
# Date created:		Mon Oct  3 22:06:21 EDT 1994
# Whom:			rww
#
# $Id: Makefile,v 1.3 1995/02/11 13:49:46 asami Exp $
#

DISTNAME=	itcl-1.5
HAS_CONFIGURE=	yes
MASTER_SITES=	ftp://ftp.aud.alcatel.com/tcl/extensions/
CATEGORIES+=	languages
PATCH_STRIP=	-p1
LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

.include <bsd.port.mk>
