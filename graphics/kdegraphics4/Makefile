# New ports collection makefile for:	KDE2 Graphics
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdegraphics
PORTVERSION=	3.0
PORTREVISION=	2
CATEGORIES=	graphics kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org

USE_KDELIBS_VER=3
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=
CONFIGURE_ARGS+=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes
CONFIGURE_ARGS+=--without-kamera
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_FINAL)
CONFIGURE_ARGS+=--enable-final
.endif
.if defined(PARALLEL_PACKAGE_BUILD) || defined(WANT_KDE_NDEBUG)
CONFIGURE_ARGS+=--disable-debug
.endif

LIB_DEPENDS+=	Imlib.5:${PORTSDIR}/graphics/imlib

.include <bsd.port.pre.mk>

# temporarily disable kamera, it requires gphoto2
PLIST_SUB+=	KAMERA="@comment "

SANE_CONFIG=	${LOCALBASE}/bin/sane-config

.if exists(${SANE_CONFIG})
WITH_SANE=	yes
.endif

.if defined(WITH_SANE) && ${WITH_SANE} == yes
LIB_DEPENDS+=	sane.1:${PORTSDIR}/graphics/sane-backends
PLIST_SUB+=	SANE=""
.else
PLIST_SUB+=	SANE="@comment "
pre-everything::
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with scanner (SANE) support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SANE=yes\""
	@${ECHO_MSG}
.endif

.include <bsd.port.post.mk>
