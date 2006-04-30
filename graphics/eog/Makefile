# New ports collection makefile for:	eog2
# Date created:		21 May 2002
# Whom:			Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/graphics/eog/Makefile,v 1.29 2006/04/13 07:52:35 bland Exp $
#

PORTNAME=	eog
PORTVERSION=	2.14.1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME:S/2$//}/${PORTVERSION:C/^([0-9]+\.[0-9]+).*/\1/}
DIST_SUBDIR=	gnome2

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	The Eye Of Gnome image viewer

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack intlhack libgnomeprintui \
		librsvg2 desktopfileutils gnomedesktop
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
GNU_CONFIGURE=	yes
GNOME_DESKTOP_VERSION=2
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

GCONF_SCHEMAS=	eog.schemas

.include <bsd.port.pre.mk>

.if defined(PACKAGE_BUILDING) || defined(PARALLEL_PACKAGE_BUILD)
WITH_EXIF=	yes
.endif

.if defined(WITH_EXIF) || exists(${LOCALBASE}/lib/libexif.so.12)
LIB_DEPENDS+=	exif.12:${PORTSDIR}/graphics/libexif
.endif

post-install:
	@-update-desktop-database > /dev/null

.include <bsd.port.post.mk>
