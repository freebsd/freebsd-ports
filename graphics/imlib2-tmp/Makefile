# New ports collection makefile for:   imlib
# Version required:    0.7
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.8 1997/11/04 03:57:54 asami Exp $
#

DISTNAME=	imlib_DR-0.7
PKGNAME=	imlib-0.7
CATEGORIES=	graphics
MASTER_SITES=	ftp://cthulhu.mandrake.net/pub/imlib/ \
		http://www.rasterman.com/ftp/

MAINTAINER=	vanilla@MinJe.com.TW

RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		tgatoppm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/imlib

MAN3=		imlib.3x

post-patch:
	$(CP) $(WRKSRC)/Imakefile $(WRKSRC)/Imakefile.pat
	${SED} -e "s%X11BASE%$(X11BASE)%" <$(WRKSRC)/Imakefile.pat >$(WRKSRC)/Imakefile

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
