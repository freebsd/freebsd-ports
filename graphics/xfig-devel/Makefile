# New ports collection makefile for:	xfig
# Version required:	3.1.3
# Date created:		4 January 1995
# Whom:			roberto
#
# $Id: Makefile,v 1.9 1995/04/09 07:09:49 asami Exp $
#

DISTNAME=	xfig.3.1.3
PKGNAME=	xfig-3.1.3
CATEGORIES+=	graphics x11
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/drawing_tools/xfig/ \
	ftp://crl.dec.com/pub/X11/contrib/applications/drawing_tools/xfig/

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/xfig
USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  \
		XFIGLIBDIR=${PREFIX}/lib/X11/xfig  -f

.include <bsd.port.mk>
