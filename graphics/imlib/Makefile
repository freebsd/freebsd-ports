# New ports collection makefile for:   imlib
# Version required:    0.1
# Date created:        10 June 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	imlib
PKGNAME=	imlib-0.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.cse.unsw.edu.au/pub/users/s2154962/
DISTFILES=	imlib_DR-0.1.tar.gz

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

RUN_DEPENDS=	tgatoppm:${PORTSDIR}/graphics/netpbm \
		djpeg:${PORTSDIR}/graphics/jpeg \
		convert:${PORTSDIR}/graphics/ImageMagick

USE_GMAKE=	yes
USE_IMAKE=	yes

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
