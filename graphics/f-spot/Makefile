# New ports collection makefile for:		f-spot
# Date created:					20041008
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.26 2006/02/15 02:36:17 tmclau02 Exp $
#

PORTNAME=	f-spot
PORTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.1

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	Personal photo management to the GNOME desktop

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		exif.12:${PORTSDIR}/graphics/libexif \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
BUILD_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp
RUN_DEPENDS=	gapi2-fixup:${PORTSDIR}/x11-toolkits/gtk-sharp20 \
		${LOCALBASE}/lib/mono/dbus-sharp/dbus-sharp.dll:${PORTSDIR}/devel/dbus-sharp

USE_BZIP2=	yes
USE_SQLITE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} 's|target="liblcms.so.1"|target="liblcms.so"|g ; \
		s|target="libexif.so.@EXIF_SOVERSION@"|target="libexif.so"|g' \
		${WRKSRC}/src/f-spot.exe.config.in

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
