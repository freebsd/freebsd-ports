# New ports collection makefile for:   imlib
# Version required:    0.11
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.10 1997/11/26 22:38:57 vanilla Exp $
#

DISTNAME=	imlib_DR-0.11
PKGNAME=	imlib-0.11
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.mandrake.net/pub/imlib/ \
		http://www.rasterman.com/ftp/

MAINTAINER=	vanilla@MinJe.com.TW

LIB_DEPENDS=	png\\.0\\.:${PORTSDIR}/graphics/png \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34

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
