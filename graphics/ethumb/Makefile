# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ethumb
PORTVERSION=	1.7.9
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Thumbnail generator library

LICENSE=	LGPL21

LIB_DEPENDS=	libexif.so:${PORTSDIR}/graphics/libexif

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig
USE_EFL=	eina evas ecore edje libtool_hack
USE_EFL_ECORE=	evas file x11 input_evas
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--disable-epdf

OPTIONS_DEFINE=	EMOTION ETHUMBD
OPTIONS_DEFAULT=EMOTION ETHUMBD
EMOTION_DESC=	Build with Emotion module
ETHUMBD_DESC=	Build ethumbd daemon (requires dbus)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMOTION}
USE_EFL+=	emotion
CONFIGURE_ARGS+=--enable-emotion
PLIST_SUB+=	EMOTION=""
.else
CONFIGURE_ARGS+=--disable-emotion
PLIST_SUB+=	EMOTION="@comment "
.endif

.if ${PORT_OPTIONS:METHUMBD}
USE_EFL+=	edbus
PLIST_SUB+=	ETHUMBD=""
CONFIGURE_ARGS+=--enable-ethumbd
.else
PLIST_SUB+=	ETHUMBD="@comment "
CONFIGURE_ARGS+=--disable-ethumbd
.endif

.include <bsd.port.mk>
