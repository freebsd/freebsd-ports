# New ports collection makefile for:	imlib
# Version required:	1.8.1
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.33 1998/09/23 17:07:43 vanilla Exp $
#

DISTNAME=	imlib-1.8.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.enlightenment.org/pub/enlightenment/enlightenment/ \
		ftp://www.rasterman.com/pub/enlightenment/enlightenment/ \
		ftp://ftp.labs.redhat.com/pub/imlib/TAR/

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=    png.2:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff34.1:${PORTSDIR}/graphics/tiff34 \
		gif.3:${PORTSDIR}/graphics/giflib \
		gtk11.1:${PORTSDIR}/x11-toolkits/gtk11

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include \
		GTK_CONFIG="${X11BASE}/bin/gtk11-config" \
		LIBS=-L${LOCALBASE}/lib \
		INSTALL="$${INSTALL} -c"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
