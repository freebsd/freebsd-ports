# New ports collection makefile for:   imlib
# Version required:    0.5
# Date created:        18 August 1997
# Whom:                Vanill I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.4 1997/09/14 19:36:41 max Exp $
#

DISTNAME=	imlib_DR-0.5
PKGNAME=	imlib-0.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.rasterman.com/ftp/ \
		ftp://cthulhu.mandrake.net/pub/enlightenment/

MAINTAINER=	vanilla@MinJe.com.TW

RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		tgatoppm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/imlib

post-patch:
	$(CP) $(WRKSRC)/Imakefile $(WRKSRC)/Imakefile.pat
	${SED} -e "s%X11BASE%$(X11BASE)%" <$(WRKSRC)/Imakefile.pat >$(WRKSRC)/Imakefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
