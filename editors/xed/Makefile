# New ports collection makefile for:	xed
# Version required:	1.3
# Date created:		28 Jul 1996
# Whom:			shanee
#
# $Id: Makefile,v 1.2 1996/07/30 00:10:31 chuckr Exp $
#

DISTNAME=	xed1.3
PKGNAME=	xed-1.3
CATEGORIES+=	editors x11
MASTER_SITES=	ftp://ftp.x.org/contrib/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	shanee@rabbit.augusta.de

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf

pre-install:
	cd $(WRKSRC); make install.man

.include <bsd.port.mk>
