# New ports collection makefile for:	imlib
# Version required:	1.7
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.22 1998/06/23 06:43:12 vanilla Exp $
#

DISTNAME=	imlib-1.7
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=    png\\.2\\.:${PORTSDIR}/graphics/png \
		jpeg\\.9\\.:${PORTSDIR}/graphics/jpeg \
		tiff34\\.1\\.:${PORTSDIR}/graphics/tiff34 \
		gif\\.3\\.:${PORTSDIR}/graphics/giflib \
		gtk\\.1\\.4:${PORTSDIR}/x11/gtk

USE_GMAKE=	yes
USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		LIBS=-L${LOCALBASE}/lib \
		INSTALL="$${INSTALL} -c"
WRKSRC=		${WRKDIR}/imlib

post-install:
	${LDCONFIG} -m ${PREFIX}/lib

.include <bsd.port.mk>
