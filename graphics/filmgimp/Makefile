# New ports collection makefile for:	filmgimp
# Date created:				25 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	filmgimp
PORTVERSION=	0.16
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An editing tool used for painting and retouching of movies

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		tiff.4:${PORTSDIR}/graphics/tiff \
		IlmImf.0:${PORTSDIR}/graphics/OpenEXR

USE_GCC=	3.1+
USE_X_PREFIX=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-openexr-prefix=${LOCALBASE}
USE_GMAKE=	yes
USE_GNOME=	gtk12
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes

.include <bsd.port.pre.mk>

.if defined(USE_GCC) && ${USE_GCC} == 3.1+ && ${OSVERSION} < 500035
CC=		${LOCALBASE}/bin/gcc31
CXX=		${LOCALBASE}/bin/g++31
BUILD_DEPENDS+=	gcc31:${PORTSDIR}/lang/gcc31
MAKE_ENV+=	CC=${CC} CXX=${CXX}
.endif

MAN1=		filmgimp.1 filmgimptool.1

.if ${OSVERSION} >= 501000
BROKEN=		"Does not compile"
.endif

post-configure:
# this must be done to avoid conflicts with ${X11BASE}/include/libgimp/
	@${FIND} ${WRKSRC} -name "Makefile" | \
		${XARGS} ${EGREP} -l '(\-I${X11BASE}/include|\-L/lib)' | \
		${XARGS} ${REINPLACE_CMD} -E -e \
		's|-I${X11BASE}/include[:^/:]*$$||g; \
		s|-L/lib||'
# fix if PREFIX =! X11BASE
	@${REINPLACE_CMD} -E -e \
		's|(-I\$$\(includedir\))|\1 -I${X11BASE}/include|' \
		${WRKSRC}/plug-ins/dbbrowser/Makefile \
		${WRKSRC}/app/Makefile

.include <bsd.port.post.mk>
