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

USE_KDELIBS_VER=3
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

.if defined(WITH_IMLIB) || defined(KDE_WITH_IMLIB)
USE_GNOMENG=	yes
USE_GNOME=	imlib
PLIST_SUB+=	IMLIB=""
CONFIGURE_ARGS+=	--with-imlib-config=${X11BASE}/bin
.else
WITHOUT_IMLIB=	yes
PLIST_SUB+=	IMLIB="@comment "
CONFIGURE_ARGS+=	--without-imlib-config
.endif

.include "${.CURDIR}/../../x11/kde3/Makefile.kde"

.include <bsd.port.pre.mk>

GPHOTO2_CONFIG=	${LOCALBASE}/bin/gphoto2-config

.if exists(${GPHOTO2_CONFIG})
WITH_GPHOTO2?=	yes
.endif

.if defined(WITH_GPHOTO2) && ${WITH_GPHOTO2} == yes
LIB_DEPENDS+=	gphoto2.2:${PORTSDIR}/graphics/gphoto2
PLIST_SUB+=	KAMERA=""
.else
PLIST_SUB+=	KAMERA="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "If you want to compile with digital camera support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_GPHOTO2=yes\""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG}
.endif

SANE_CONFIG=	${LOCALBASE}/bin/sane-config

.if exists(${SANE_CONFIG})
WITH_SANE?=	yes
.endif

.if defined(WITH_SANE) && ${WITH_SANE} == yes
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
PLIST_SUB+=	SANE=""
.else
PLIST_SUB+=	SANE="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG} "If you want to compile with scanner (SANE) support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SANE=yes\""
	@${ECHO_MSG} "======================================================="
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
