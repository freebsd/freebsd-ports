# New ports collection makefile for:	xed
# Version required:	1.3
# Date created:		28 Jul 1996
# Whom:			shanee
#
# $Id: Makefile,v 1.5 1996/11/18 09:52:52 asami Exp $
#

DISTNAME=	xed1.3
PKGNAME=	xed-1.3
CATEGORIES=	editors x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	editors
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	shanee@augusta.de

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf

pre-install:
	cd $(WRKSRC); make install.man

.include <bsd.port.mk>
