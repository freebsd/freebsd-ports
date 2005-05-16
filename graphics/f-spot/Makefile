# New ports collection makefile for:		f-spot
# Date created:					20041008
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $Id: Makefile,v 1.5 2005/05/16 03:31:37 mezz7 Exp $
# $FreeBSD$
#

PORTNAME=	f-spot
PORTVERSION=	0.0.13
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.0

MAINTAINER=	tmclaugh@sdf.lonestar.org
COMMENT=	Personal photo management to the GNOME desktop

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		exif.12:${PORTSDIR}/graphics/libexif \
		sqlite.2:${PORTSDIR}/databases/sqlite2 \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	gapi-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack
USE_X_PREFIX=	yes
USE_LIBTOOL_VER=15
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
