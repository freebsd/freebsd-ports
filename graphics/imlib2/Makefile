# New ports collection makefile for:   imlib
# Version required:    0.5.1
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.7 1997/11/04 00:32:46 max Exp $
#

DISTNAME=	imlib_DR-0.5.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://cthulhu.mandrake.net/pub/imlib/

MAINTAINER=	vanilla@MinJe.com.TW

RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		tgatoppm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/imlib-0.5.1

post-patch:
	$(CP) $(WRKSRC)/Imakefile $(WRKSRC)/Imakefile.pat
	${SED} -e "s%X11BASE%$(X11BASE)%" <$(WRKSRC)/Imakefile.pat >$(WRKSRC)/Imakefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
