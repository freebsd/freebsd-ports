# New ports collection makefile for:	xfig
# Version required:	3.1.4
# Date created:		4 January 1995
# Whom:			roberto
#
# $Id: Makefile,v 1.12 1995/10/03 21:58:31 ache Exp $
#

DISTNAME=	xfig.3.1.4
PKGNAME=	xfig-3.1.4
CATEGORIES=	graphics x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/drawing_tools/xfig

MAINTAINER=	asami@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm \
		jpeg\\.6\\.:${PORTSDIR}/graphics/jpeg

USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/X11/app-defaults  \
		XFIGLIBDIR=${PREFIX}/lib/X11/xfig  -f

.include <bsd.port.mk>
