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

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

OPTIONS=	IMLIB "Build Kuickshow, a fast and versatile image viewer" off \
		GPHOTO2 "Enable support for digital cameras" off \
		SANE "Build Kooka, a SANE scanner frontend for KDE" off

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

.if exists (${X11BASE}/bin/imlib-config)
.	if !defined(WITH_IMLIB)
IMLIB_OVERRIDE=	yes
WITH_IMLIB=	yes
.	endif
.endif

.if exists(${LOCALBASE}/bin/gphoto2-config)
.	if !defined(WITH_GPHOTO2)
GPHOTO2_OVERRIDE=	yes
WITH_GPHOTO2=		yes
.	endif
.endif

.if exists (${LOCALBASE}/bin/sane-config)
.	if !defined(WITH_SANE)
SANE_OVERRIDE=	yes
WITH_SANE=	yes
.	endif
.endif

.if defined(WITH_IMLIB)
USE_GNOME=	imlib
PLIST_APPEND+=	plist.imlib
CONFIGURE_ARGS+=--with-imlib-config=${X11BASE}/bin
.else
WITHOUT_IMLIB=	yes
CONFIGURE_ARGS+=--without-imlib-config
.endif

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/gphoto2
PLIST_APPEND+=	plist.gphoto2
.endif

.if defined(WITH_SANE)
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
PLIST_APPEND+=	plist.sane
RUN_DEPENDS+=	${LOCALBASE}/bin/gocr:${PORTSDIR}/graphics/gocr
.endif

pre-everything::
.if defined(IMLIB_OVERRIDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "*     imlib is installed but WITH_IMLIB is not set!    *"
	@${ECHO_MSG} "*      WITH_IMLIB has been enabled automatically.      *"
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG}
.endif
.if defined(GPHOTO2_OVERRIDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "*  gphoto2 is installed but WITH_GPHOTO2 is not set!   *"
	@${ECHO_MSG} "*     WITH_GPHOTO2 has been enabled automatically.     *"
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG}
.endif
.if defined(SANE_OVERRIDE)
	@${ECHO_MSG}
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG} "* sane-backends is installed but WITH_SANE is not set! *"
	@${ECHO_MSG} "*      WITH_SANE has been enabled automatically.       *"
	@${ECHO_MSG} "********************************************************"
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
