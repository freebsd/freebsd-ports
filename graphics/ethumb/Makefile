# New ports collection makefile for:	ethumb
# Date created:				29 August 2010
# Whom:					Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	ethumb
PORTVERSION=	0.1.0.52995
PORTREVISION=	1
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://files.roorback.net/e17/2010-10-03/extra/

MAINTAINER=	magik@roorback.net
COMMENT=	Thumbnail generator library

LIB_DEPENDS=	exif.12:${PORTSDIR}/graphics/libexif

LICENSE=	LGPL21
DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eina evas ecore edje libtool_hack
USE_EFL_ECORE=	evas file x11 input_evas
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-epdf

OPTIONS=	EMOTION "Build with Emotion module" on \
		ETHUMBD "Build ethumbd daemon (requires dbus)" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_EMOTION)
USE_EFL+=	emotion
CONFIGURE_ARGS+=	--enable-emotion
PLIST_SUB+=	EMOTION=""
.else
CONFIGURE_ARGS+=	--disable-emotion
PLIST_SUB+=	EMOTION="@comment "
.endif

.if !defined(WITHOUT_ETHUMBD)
USE_EFL+=	edbus
PLIST_SUB+=	ETHUMBD=""
CONFIGURE_ARGS+=	--enable-ethumbd
.else
PLIST_SUB+=	ETHUMBD="@comment "
CONFIGURE_ARGS+=	--disable-ethumbd
.endif

.include <bsd.port.post.mk>
