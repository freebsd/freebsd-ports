# New ports collection makefile for:	bugbuddy2
# Date created:				14 May 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	bugbuddy
PORTVERSION=	2.10.0
PORTREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/bug-buddy/2.10
DISTNAME=	bug-buddy-${PORTVERSION}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A bug reporting tool for GNOME 2

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-doc-utils.pc:${PORTSDIR}/textproc/gnomedocutils
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/gnome-doc-utils.pc:${PORTSDIR}/textproc/gnomedocutils

USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomeprefix gnomehack intlhack gnomedesktop gnomemenus \
		desktopfileutils
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-help-dir=${PREFIX}/share/gnome/help

MAN1=		bug-buddy.1
GCONF_SCHEMAS=	bug-buddy.schemas

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
