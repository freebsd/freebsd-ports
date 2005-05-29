# New ports collection makefile for:	eclipse
# Date created:				March 7, 2003
# Whom:					various members of freebsd-java
#
# $FreeBSD$
#

PORTNAME=	eclipse
PORTVERSION=	3.0.1
PORTREVISION=	4
CATEGORIES=	java devel
MASTER_SITES=	${MASTER_SITE_ECLIPSE}
MASTER_SITE_SUBDIR=	R-${PORTVERSION}-200409161125
DISTNAME=	${PORTNAME}-sourceBuild-srcIncluded-${PORTVERSION}
DIST_SUBDIR=	eclipse

MAINTAINER=	java@FreeBSD.ORG
COMMENT=	An open extensible IDE for anything and nothing in particular

BUILD_DEPENDS=	ant:${PORTSDIR}/devel/apache-ant \
		zip:${PORTSDIR}/archivers/zip
BUILD_DEPENDS+=	${EXTRACT_DEPENDS}

ONLY_FOR_ARCHS=	i386
USE_GMAKE=	yes
USE_ZIP=	yes
USE_GCC=	3.4

USE_JAVA=	yes
JAVA_VERSION=	1.4+
JAVA_OS=	native

USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes
PLIST_SUB=	BUILD=${ECLIPSE_BUILD} WS=${ECLIPSE_WS} RELEASEVERSION=${PORTVERSION}

ECLIPSE_BUILD=	3063
ECLIPSE_OS=	freebsd
ECLIPSE_ARCH=	x86

.if defined(WITH_MOTIF)
ECLIPSE_WS=	motif
USE_ICONV=	yes
USE_MOTIF=	yes
PLIST_SUB+=	GTK:="@comment "
PLIST_SUB+=	MOTIF:=""
.else
ECLIPSE_WS=	gtk
PLIST_SUB+=	GTK:=""
PLIST_SUB+=	MOTIF:="@comment "
.if defined(WITH_MOZILLA) && ${WITH_MOZILLA} == "firefox"
BUILD_DEPENDS+=	firefox:${PORTSDIR}/www/firefox
BROWSER=	firefox
.else
BUILD_DEPENDS+=	mozilla:${PORTSDIR}/www/mozilla
BROWSER=	mozilla
.endif
.endif

.if defined(WITHOUT_GNOMEVFS)
MAKE_GNOME=
USE_GNOME=	gtk20 pkgconfig
PLIST_SUB+=	GNOME:="@comment "
.else
MAKE_GNOME=	make_gnome
USE_GNOME=	gtk20 gnomevfs2 libgnome libgnomeui pkgconfig
PLIST_SUB+=	GNOME:=""
.endif

MAKE_ARGS=	BROWSER=${BROWSER} \
		ECLIPSE_BUILD=${ECLIPSE_BUILD} \
		ECLIPSE_ARCH=${ECLIPSE_ARCH} \
		ECLIPSE_OS=${ECLIPSE_OS} \
		ECLIPSE_WS=${ECLIPSE_WS} \
		JAVA_HOME=${JAVA_HOME} \
		MAKE_GNOME=${MAKE_GNOME}

SCRIPTS_ENV=	ECLIPSE_WS="${ECLIPSE_WS}"

.include <bsd.port.pre.mk>

# The Motif version builds a KDE/Qt library if kdebase is around
.if defined(WITH_MOTIF)
BUILD_KDE=`${PKG_INFO} -xc kdebase | ${GREP} "no packages match"`
.if empty(BUILD_KDE)
PLIST_SUB+=	KDE:=""
.else
PLIST_SUB+=	KDE:="@comment *${BUILD_KDE}*"
.endif
.endif

.include <bsd.port.post.mk>
