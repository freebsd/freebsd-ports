# New ports collection makefile for:	imlib
# Version required:	1.9.2
# Date created:		10 June 1997
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.41 1999/01/20 22:49:40 vanilla Exp $
#

DISTNAME=	imlib-1.9.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	imlib

MAINTAINER=	vanilla@FreeBSD.ORG

LIB_DEPENDS=    png.2:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34 \
		gif.3:${PORTSDIR}/graphics/giflib \
		gtk11d.1:${PORTSDIR}/x11-toolkits/gtk11-devel

USE_GMAKE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${X11BASE}/bin/gtk11d-config" \
		LIBS="-L${LOCALBASE}/lib"

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
	${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>
