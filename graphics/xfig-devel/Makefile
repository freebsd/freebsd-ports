# New ports collection makefile for:	xfig
# Version required:	3.1.3
# Date created:		4 January 1995
# Whom:			asami
# Original by:		roberto
#
# $Id: Makefile,v 1.6 1995/02/27 23:51:31 jmz Exp $
#

DISTNAME=	xfig.3.1.3
PKGNAME=	xfig-3.1.3
WRKSRC=		${WRKDIR}/xfig
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/drawing_tools/xfig/ \
	ftp://crl.dec.com/pub/X11/contrib/applications/drawing_tools/xfig/
MAINTAINER=	asami@FreeBSD.ORG
LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm
USE_IMAKE=	yes
MAKE_FLAGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/man/man1 \
		XAPPLOADDIR=${PREFIX}/lib/app-defaults  \
		XFIGLIBDIR=${PREFIX}/lib/xfig  -f

.include <bsd.port.mk>
