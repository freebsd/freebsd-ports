# New ports collection makefile for:	xfig
# Version required:	3.2
# Date created:		4 January 1995
# Whom:			roberto
#
# $Id: Makefile,v 1.16 1997/08/28 04:27:47 chuckr Exp $
#

DISTNAME=	xfig.3.2
PKGNAME=	xfig-3.2
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		Xaw3d\\.6\\.:${PORTSDIR}/x11/Xaw3d
RUN_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  \
		XFIGLIBDIR=${PREFIX}/lib/X11/xfig  -f

.include <bsd.port.mk>
