# New ports collection makefile for:	itcl
# Version required:	1.5
# Date created:		Mon Oct  3 22:06:21 EDT 1994
# Whom:			rww
#
# $Id: Makefile,v 1.4 1995/04/01 12:46:55 jkh Exp $
#

DISTNAME=	itcl-1.5
HAS_CONFIGURE=	yes
CATEGORIES+=	languages
MASTER_SITES=	ftp://ftp.aud.alcatel.com/tcl/extensions/

LIB_DEPENDS=	tcl\\.7\\.:${PORTSDIR}/lang/tcl \
		tk\\.3\\.:${PORTSDIR}/x11/tk

PATCH_STRIP=	-p1

.include <bsd.port.mk>
