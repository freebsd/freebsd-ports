# New ports collection makefile for:	quat-gui
# Date created:				2 May 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	quat
PORTVERSION=	1.20
CATEGORIES=	graphics
MASTER_SITES=	http://www.physcip.uni-stuttgart.de/phy11733/download/
PKGNAMESUFFIX=	-gui
DISTNAME=	quat-${PORTVERSION:S/.p/pre/}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A Three-dimensional fractal creator (X11 GUI)

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -L${X11BASE}/lib" \
		LIBS="-lXext -lGL" FLUID="${X11BASE}/bin/fluid}"

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math
.endif

pre-everything::
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG} "You can enable additional compilation optimizations"
	@${ECHO_MSG} "by defining WITH_OPTIMIZED_CFLAGS"
.endif

post-patch:
	@${REINPLACE_CMD} -E -e \
		's|^...CFLAGS=|#CFLAGS=|; \
		s|^...CXXFLAGS=|#CXXFLAGS=|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e 's|-I\.[[:space:]]+-I\$$\(srcdir\)[[:space:]]+||' \
		${WRKSRC}/gui/Makefile.in
# disable data file installation since distfile does not do
# The Right Thing(TM)
	@${REINPLACE_CMD} -E -e \
		's|^(install-data-am:).*$$|\1|' \
		${WRKSRC}/Makefile.in

post-configure:
	@${REINPLACE_CMD} -E -e \
		's|^(pkgdatadir).*$$|\1=${PREFIX}/share/${PORTNAME}${PKGNAMESUFFIX}|' \
		${WRKSRC}/doc/Makefile

.include <bsd.port.mk>
