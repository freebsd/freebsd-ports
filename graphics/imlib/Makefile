# New ports collection makefile for:	imlib
# Version required:	1.1
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.17 1998/03/28 19:49:58 ache Exp $
#

DISTNAME=	Imlib-1.1
PKGNAME=	imlib-1.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/imlib/TAR/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=    png\\.2\\.:${PORTSDIR}/graphics/png \
		jpeg\\.8\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		gif\\.3\\.:${PORTSDIR}/graphics/giflib

USE_GMAKE=	yes
USE_X11=	ues
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/imlib/Imlib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
