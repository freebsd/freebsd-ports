# New ports collection makefile for:	pixmap
# Version required:	2.6
# Date created:		19 February 1995
# Whom:			jmz
#
# $Id: Makefile,v 1.6 1995/04/09 07:09:39 asami Exp $
#

DISTNAME=	pixmap2.6
PKGNAME=	pixmap-2.6
CATEGORIES+=	graphics
MASTER_SITES=	ftp://crl.dec.com/pub/X11/contrib/applications/pixmap/
MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/pixmap
USE_IMAKE=	yes

.include <bsd.port.mk>
