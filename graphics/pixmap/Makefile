# New ports collection makefile for:	pixmap
# Version required:	2.6
# Date created:		19 February 1995
# Whom:			jmz
#
# $Id: Makefile,v 1.7 1995/04/11 02:00:42 jmz Exp $
#

DISTNAME=	pixmap2.6
PKGNAME=	pixmap-2.6
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications/pixmap

MAINTAINER=	jmz@FreeBSD.org

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

WRKSRC=		${WRKDIR}/pixmap
USE_IMAKE=	yes

.include <bsd.port.mk>
