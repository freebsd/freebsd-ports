# New ports collection makefile for:	xed
# Version required:	1.3
# Date created:		28 Jul 1996
# Whom:			shanee
#
# $Id$
#

DISTNAME=	xed1.3
PKGNAME=	xed-1.3
MASTER_SITES=	ftp://ftp.x.org/contrib/editors/
CATEGORIES+=	editors x11

MAINTAINER=	shanee@rabbit.augusta.de

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
XMKMF=		xmkmf
EXTRACT_SUFX=	.tar.Z

pre-install:
	cd $(WRKSRC); make install.man

.include <bsd.port.mk>
