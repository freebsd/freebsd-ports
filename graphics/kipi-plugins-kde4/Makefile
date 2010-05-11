# New ports collection makefile for:	kipi-plugins-kde4
# Date created:				Jan 23, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	kipi-plugins
PORTVERSION=	1.2.0
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF/kipi/${PORTNAME}/${PORTVERSION}

MAINTAINER=	kris@pcbsd.org
COMMENT=	KDE4 kipi graphics plugins

LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		kipi.7:${PORTSDIR}/graphics/kdegraphics4
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

LATEST_LINK=	${PORTNAME}-kde4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GETTEXT=	yes
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

OPTIONS=	GPOD "Enable Ipod Export plugin" ON \
		OPENCV "Enable Red Eye Removal plugin" ON \
		PIMLIBS "Enable Calendar plugin" ON

.include <bsd.port.options.mk>

.if defined(WITH_GPOD)
LIB_DEPENDS+=	gpod.5:${PORTSDIR}/audio/libgpod
PLIST_SUB+=	GPOD=""
.else
CMAKE_ARGS+=	-DWITH_GLIB2:BOOL=OFF \
		-DWITH_GObject:BOOL=OFF \
		-DWITH_Gdk:BOOL=OFF \
		-DWITH_Gpod:BOOL=OFF
PLIST_SUB+=	GPOD="@comment "
.endif

.if defined(WITH_OPENCV)
LIB_DEPENDS+=	cv.2:${PORTSDIR}/graphics/opencv
PLIST_SUB+=	OPENCV=""
.else
CMAKE_ARGS+=	-DWITH_OpenCV:BOOL=OFF
PLIST_SUB+=	OPENCV="@comment "
.endif

.if defined(WITH_PIMLIBS)
USE_KDE4+=	pimlibs
PLIST_SUB+=	PIMLIBS=""
.else
CMAKE_ARGS+=	-DWITH_KdepimLibs:BOOL=OFF
PLIST_SUB+=	PIMLIBS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<endian.h>|<sys/endian.h>|g' \
		${PATCH_WRKSRC}/dngconverter/dngwriter/extra/dng_sdk/dng_flags.h

.include <bsd.port.mk>
