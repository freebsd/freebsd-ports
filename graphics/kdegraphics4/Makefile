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
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Graphics utilities for the KDE3 integrated X11 desktop

LIB_DEPENDS=	glut:${PORTSDIR}/graphics/libglut

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}
KDE_BUILD_PLIST=yes

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WANT_GNOME=	yes

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib %%PREFIX%%/lib/kde3

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"
.include <bsd.port.pre.mk>

IMLIB_CONFIG=	${X11BASE}/bin/imlib-config

.if exists(${IMLIB_CONFIG})
WITH_IMLIB?=	yes
.endif

.if defined(WITH_IMLIB) || defined(KDE_WITH_IMLIB)
USE_GNOME=	imlib
PLIST_APPEND+=	plist.imlib
CONFIGURE_ARGS+=--with-imlib-config=${X11BASE}/bin
.else
WITHOUT_IMLIB=	yes
CONFIGURE_ARGS+=--without-imlib-config
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "If you want to compile with imlib support (enables"
	@${ECHO_MSG} "kuickshow), hit Ctrl-C right now and use"
	@${ECHO_MSG} "\"make WITH_IMLIB=yes\""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG}
.endif # defined(WITH_IMLIB) || defined(KDE_WITH_IMLIB)

GPHOTO2_CONFIG=	${LOCALBASE}/bin/gphoto2-config

.if exists(${GPHOTO2_CONFIG})
WITH_GPHOTO2?=	yes
.endif # exists(${GPHOTO2_CONFIG})

.if defined(WITH_GPHOTO2)
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/gphoto2
PLIST_APPEND+=	plist.gphoto2
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "If you want to compile with digital camera support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GPHOTO2=yes\""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG}
.endif # defined(WITH_GPHOTO2)

SANE_CONFIG=	${LOCALBASE}/bin/sane-config

.if exists(${SANE_CONFIG})
WITH_SANE?=	yes
.endif # exists(${SANE_CONFIG})

.if defined(WITH_SANE)
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
PLIST_APPEND+=	plist.sane
RUN_DEPENDS=	${LOCALBASE}/bin/gocr:${PORTSDIR}/graphics/gocr
.else
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "If you want to compile with scanner (SANE) support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SANE=yes\""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG}
.endif # defined(WITH_SANE)

.include <bsd.port.post.mk>
