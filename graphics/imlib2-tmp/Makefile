# New ports collection makefile for:	imlib
# Version required:	1.0
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.13 1998/02/18 15:36:01 vanilla Exp $
#

DISTNAME=	Imlib-1.0
PKGNAME=	imlib-1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/imlib/TAR/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=	png\\.0\\.:${PORTSDIR}/graphics/png \
		jpeg\\.7\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34
RUN_DEPENDS=	djpeg:${PORTSDIR}/graphics/jpeg \
		tgatoppm:${PORTSDIR}/graphics/netpbm \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
USE_X11=	ues
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/imlib/Imlib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
