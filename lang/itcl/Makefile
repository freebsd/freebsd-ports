# New ports collection makefile for:	itcl
# Version required:	1.5
# Date created:		Mon Oct  3 22:06:21 EDT 1994
# Whom:			rww
#
# $Id: Makefile,v 1.6 1995/05/13 07:53:08 asami Exp $
#

DISTNAME=	itcl-1.5
HAS_CONFIGURE=	yes
CATEGORIES+=	languages
MASTER_SITES=	ftp://ftp.aud.alcatel.com/tcl/extensions/

DEPENDS=	${PORTSDIR}/lang/tcl
LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk

PATCH_STRIP=	-p1

post-install:
	ldconfig -m ${PREFIX}/lib

.include <bsd.port.mk>
