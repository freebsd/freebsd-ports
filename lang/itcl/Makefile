# New ports collection makefile for:	itcl
# Version required:	1.5
# Date created:		Mon Oct  3 22:06:21 EDT 1994
# Whom:			rww
#
# $Id: Makefile,v 1.9 1995/11/22 13:12:52 asami Exp $
#

DISTNAME=	itcl-1.5
HAS_CONFIGURE=	yes
CATEGORIES+=	lang
MASTER_SITES=	ftp://ftp.neosoft.com/pub/tcl/alcatel/extensions/

DEPENDS=	${PORTSDIR}/lang/tcl
LIB_DEPENDS=	tk\\.3\\.:${PORTSDIR}/x11/tk

PATCH_STRIP=	-p1

.include <bsd.port.mk>
