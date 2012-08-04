# -*-mode: makefile-*-
# New ports collection makefile for:	KDE3 Graphics
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	11
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics utilities for the KDE3 integrated X11 desktop

BUILD_DEPENDS=	kpsewhich:${PORTSDIR}/print/teTeX-base
LIB_DEPENDS=	art_lgpl_2.5:${PORTSDIR}/graphics/libart_lgpl \
		fontconfig.1:${PORTSDIR}/x11-fonts/fontconfig \
		freetype.9:${PORTSDIR}/print/freetype2 \
		fribidi.3:${PORTSDIR}/converters/fribidi \
		lcms.1:${PORTSDIR}/graphics/lcms \
		paper.2:${PORTSDIR}/print/libpaper

CONFLICTS=	kolourpaint-[0-9]*

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_GL=		glut
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--without-poppler
USE_GMAKE=	yes
WANT_GNOME=	yes
USE_GHOSTSCRIPT=yes
MAKE_JOBS_SAFE=	yes

USE_LDCONFIG=	yes
DO_NOT_COMPILE+=kooka kuickshow libkscan

OPTIONS_DEFINE=	IMLIB2 GPHOTO2 SANE
IMLIB2_DESC=	Build Kuickshow, a fast and versatile image viewer
GPHOTO2_DESC=	Enable support for digital cameras
SANE_DESC=	Build Kooka, a SANE scanner frontend for KDE

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MIMLIB}
RUN_DEPENDS+=	kuickshow:${PORTSDIR}/graphics/kuickshow
.else
CONFIGURE_ARGS+=--without-imlib-config
.endif

.if ${PORT_OPTIONS:MGPHOTO2}
RUN_DEPENDS+=	${LOCALBASE}/lib/kde3/kcm_kamera.la:${PORTSDIR}/graphics/kamera
.else
CONFIGURE_ARGS+=--without-kamera
.endif

.if ${PORT_OPTIONS:MSANE}
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
