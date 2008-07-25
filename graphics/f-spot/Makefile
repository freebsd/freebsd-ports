# New ports collection makefile for:		f-spot
# Date created:					20041008
# Whom:				Tom McLaughlin <tmclaugh@sdf.lonestar.org>
#
# $FreeBSD$
#   $Id: Makefile,v 1.45 2007/08/26 05:10:23 killfill Exp $
#

PORTNAME=	f-spot
PORTVERSION=	0.4.0
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.4

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	Personal photo management to the GNOME desktop

LIB_DEPENDS=	lcms.1:${PORTSDIR}/graphics/lcms \
		exif.12:${PORTSDIR}/graphics/libexif \
		gphoto2.2:${PORTSDIR}/graphics/libgphoto2
RUN_DEPENDS=	dbus-daemon:${PORTSDIR}/devel/dbus

USE_BZIP2=	yes
USE_SQLITE=	yes
USE_GNOME=	gnomehack gnomeprefix gnometarget intlhack gnomesharp20
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} 's|target="liblcms.so.1"|target="liblcms.so"|g ; \
		s|target="libexif.so.@EXIF_SOVERSION@"|target="libexif.so"|g' \
		${WRKSRC}/src/f-spot.exe.config.in
	@${REINPLACE_CMD} 's|target="libgphoto2.so.2"|target="libgphoto2.so"|g'\
	    	${WRKSRC}/libgphoto2-sharp/libgphoto2-sharp.dll.config
	@${REINPLACE_CMD} 's|#!/bin/bash|#!/bin/sh|g' \
		${WRKSRC}/tools/f-spot-import
	@${REINPLACE_CMD} 's|G_GNUC_FUNCTION|G_STRLOC|g' \
		${WRKSRC}/libfspot/f-jpeg-utils.c

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
