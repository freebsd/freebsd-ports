# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3 Graphics
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	${KDE_VERSION}
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for the KDE3 integrated X11 desktop

LIB_DEPENDS=	art_lgpl_2:${PORTSDIR}/graphics/libart_lgpl2 \
		fontconfig:${PORTSDIR}/x11-fonts/fontconfig \
		freetype:${PORTSDIR}/print/freetype2 \
		fribidi:${PORTSDIR}/converters/fribidi \
		lcms:${PORTSDIR}/graphics/lcms \
		glut:${PORTSDIR}/graphics/libglut
RUN_DEPENDS=	pdfinfo:${PORTSDIR}/graphics/xpdf

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GHOSTSCRIPT=yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

OPTIONS=	IMLIB "Build Kuickshow, a fast and versatile image viewer" off \
		GPHOTO2 "Enable support for digital cameras" off \
		SANE "Build Kooka, a SANE scanner frontend for KDE" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITH_IMLIB)
USE_GNOME=	imlib
PLIST_APPEND+=	plist.imlib
CONFIGURE_ARGS+=--with-imlib-config=${X11BASE}/bin
.elseif defined(WITHOUT_IMLIB)
WITHOUT_IMLIB=	yes
CONFIGURE_ARGS+=--without-imlib-config
.endif

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/libgphoto2
PLIST_APPEND+=	plist.gphoto2
.elseif defined(WITHOUT_GPHOTO2)
CONFIGURE_ARGS+=--without-kamera
.endif

.if defined(WITH_SANE)
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
PLIST_APPEND+=	plist.sane
RUN_DEPENDS+=	${LOCALBASE}/bin/gocr:${PORTSDIR}/graphics/gocr
.elseif defined(WITHOUT_SANE)
DO_NOT_COMPILE+=kooka libkscan
.endif

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

.include <bsd.port.post.mk>
