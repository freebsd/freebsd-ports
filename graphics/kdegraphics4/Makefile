# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3 Graphics
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	1
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
		glut:${PORTSDIR}/graphics/libglut \
		lcms:${PORTSDIR}/graphics/lcms
RUN_DEPENDS=	pdfinfo:${PORTSDIR}/graphics/xpdf

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GHOSTSCRIPT=yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3
DO_NOT_COMPILE+=kooka kuickshow libkscan

OPTIONS=	IMLIB "Build Kuickshow, a fast and versatile image viewer" off \
		GPHOTO2 "Enable support for digital cameras" off \
		SANE "Build Kooka, a SANE scanner frontend for KDE" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if defined(WITH_IMLIB)
RUN_DEPENDS+=	kuickshow:${PORTSDIR}/graphics/kuickshow
.elseif defined(WITHOUT_IMLIB)
CONFIGURE_ARGS+=--without-imlib-config
.endif

.if defined(WITH_GPHOTO2)
RUN_DEPENDS+=	${LOCALBASE}/lib/kde3/kcm_kamera.la:${PORTSDIR}/graphics/kamera
.elseif defined(WITHOUT_GPHOTO2)
CONFIGURE_ARGS+=--without-kamera
.endif

.if defined(WITH_SANE)
RUN_DEPENDS+=	kooka:${PORTSDIR}/graphics/kooka
.endif

.if defined(DO_NOT_COMPILE)
CONFIGURE_ENV+=DO_NOT_COMPILE="${DO_NOT_COMPILE}"
.endif # defined(DO_NOT_COMPILE)

pre-configure:
	${REINPLACE_CMD} \
	-E -e '/^SUBDIRS/s/(kamera|kooka|kuickshow)//g' \
		${WRKSRC}/doc/Makefile.in

.include <bsd.port.post.mk>
