# New ports collection makefile for:   imlib
# Version required:    0.4
# Date created:        18 August 1997
# Whom:                Vanill I. Shu <vanilla@MinJe.com.TW>
#
# $Id: Makefile,v 1.2 1997/08/18 17:45:11 chuckr Exp $
#

DISTNAME=	imlib_DR-0.4
PKGNAME=	imlib-0.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.rasterman.com/ftp/ \
		ftp://cthulhu.mandrake.net/pub/enlightenment/

MAINTAINER=	Vanill I. Shu <vanilla@MinJe.com.TW>

USE_GMAKE=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/imlib

post-patch:
	$(CP) $(WRKSRC)/Imakefile $(WRKSRC)/Imakefile.pat
	sed -e "s%X11BASE%$(X11BASE)%" <$(WRKSRC)/Imakefile.pat >$(WRKSRC)/Imakefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
