# New ports collection makefile for:	xmbase-grok
# Version required:	1.3.2
# Date created:		Sat Aug 30 13:29:42 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $Id$
#

DISTNAME=	xmbase-grok-1.3.2.sbin
PKGNAME=	xmbase-grok-1.3.2
CATEGORIES=	databases x11
MASTER_SITES=\
	ftp://ftp.leo.org/pub/comp/os/linux/sunsite/X11/xapps/databases/
WRKSRC=		${WRKDIR}/${PKGNAME}

MAINTAINER=	andreas@FreeBSD.ORG

LIB_DEPENDS=      Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

REQUIRES_MOTIF=	yes
USE_IMAKE=	yes
USE_X11=	yes

.include <bsd.port.mk>
