# New ports collection makefile for:	quat-gui
# Date created:				2 May 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	quat
PORTVERSION=	1.11
CATEGORIES=	graphics
MASTER_SITES=   http://www.physcip.uni-stuttgart.de/phy11733/download/
PKGNAMESUFFIX=	-gui
DISTNAME=	quat-${PORTVERSION:S/.p/pre/}

MAINTAINER=	dyeske@yahoo.com

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -L${X11BASE}/lib" LIBS="-lXext -lGL"

post-patch:
	@${REINPLACE_CMD} -E -e 's,-(march=pentium|O3|ffast-math),,g' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|-I\.[[:space:]]+-I\$$\(srcdir\)[[:space:]]+||' \
		${WRKSRC}/gui/Makefile.in

.include <bsd.port.mk>
