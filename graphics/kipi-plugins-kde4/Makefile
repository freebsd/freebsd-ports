# New ports collection makefile for:	kipi-plugins-kde4
# Date created:				Jan 23, 2009
# Whom:					Kris Moore
#
# $FreeBSD$
#

PORTNAME=	kipi-plugins
PORTVERSION=	2.7.0
PORTEPOCH=	1
CATEGORIES=	graphics kde
MASTER_SITES=	SF/digikam/digikam/${PORTVERSION}
DISTNAME=	digikam-${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE4 kipi graphics plugins

LICENSE=	GPLv2

LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		qjson:${PORTSDIR}/devel/qjson
RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

LATEST_LINK=	${PORTNAME}-kde4

OPTIONS_DEFINE=		NLS EXPOBLEND GPOD KGEOMAP KSANE KVKONTAKTE MEDIAWIKI OPENCV PIMLIBS
OPTIONS_DEFAULT=	KGEOMAP KSANE OPENCV PIMLIBS
NO_OPTIONS_SORT=	yes

EXPOBLEND_DESC=		Add runtime deps for ExpoBlending plugin
GPOD_DESC=		Enable Ipod Export plugin
KGEOMAP_DESC=		Enable GPSSync (geolocalize pictures) plugin
KSANE_DESC=		Enable Scanning plugin
KVKONTAKTE_DESC=	Enable VKontakte (VK) plugin
MEDIAWIKI_DESC=		Enable MediaWiki plugin
OPENCV_DESC=		Enable Red Eye Removal plugin
PIMLIBS_DESC=		Enable Calendar plugins

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_GL=		glu
USE_KDE4=	automoc4 kdehier kdeprefix kdelibs libkdcraw libkexiv2 libkipi
USE_QT4=	qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS=	-DCMAKE_PREFIX_PATH:PATH=${KDE4_PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}/extra/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DWITH_NLS:BOOL=OFF
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MEXPOBLEND}
RUN_DEPENDS+=	align_image_stack:${PORTSDIR}/graphics/hugin
.endif

.if ${PORT_OPTIONS:MGPOD}
LIB_DEPENDS+=	gpod:${PORTSDIR}/audio/libgpod
PLIST_SUB+=	GPOD=""
.else
CMAKE_ARGS+=	-DWITH_GLIB2:BOOL=OFF \
		-DWITH_GObject:BOOL=OFF \
		-DWITH_Gdk:BOOL=OFF \
		-DWITH_Ipod:BOOL=OFF
PLIST_SUB+=	GPOD="@comment "
.endif

.if ${PORT_OPTIONS:MKGEOMAP}
LIB_DEPENDS+=	kgeomap:${PORTSDIR}/astro/libkgeomap
PLIST_SUB+=	KGEOMAP=""
.else
CMAKE_ARGS+=	-DWITH_KGeoMap:BOOL=OFF
PLIST_SUB+=	KGEOMAP="@comment "
.endif

.if ${PORT_OPTIONS:MKSANE}
USE_KDE4+=	libksane
PLIST_SUB+=	KSANE=""
.else
CMAKE_ARGS+=	-DWITH_KSane:BOOL=OFF
PLIST_SUB+=	KSANE="@comment "
.endif

.if ${PORT_OPTIONS:MKVKONTAKTE}
LIB_DEPENDS+=	kvkontakte:${PORTSDIR}/net/libkvkontakte
PLIST_SUB+=	KVKONTAKTE=""
.else
CMAKE_ARGS+=	-DWITH_LibKVkontakte:BOOL=OFF
PLIST_SUB+=	KVKONTAKTE="@comment "
.endif

.if ${PORT_OPTIONS:MMEDIAWIKI}
LIB_DEPENDS+=	mediawiki:${PORTSDIR}/net/libmediawiki
PLIST_SUB+=	MEDIAWIKI=""
.else
CMAKE_ARGS+=	-DWITH_Mediawiki:BOOL=OFF
PLIST_SUB+=	MEDIAWIKI="@comment "
.endif

.if ${PORT_OPTIONS:MOPENCV}
LIB_DEPENDS+=	opencv_legacy:${PORTSDIR}/graphics/opencv
PLIST_SUB+=	OPENCV=""
.else
CMAKE_ARGS+=	-DWITH_OpenCV:BOOL=OFF
PLIST_SUB+=	OPENCV="@comment "
.endif

.if ${PORT_OPTIONS:MPIMLIBS}
USE_KDE4+=	pimlibs
PLIST_SUB+=	PIMLIBS=""
.else
CMAKE_ARGS+=	-DWITH_KdepimLibs:BOOL=OFF
PLIST_SUB+=	PIMLIBS="@comment "
.endif

post-patch:
	${LN} -s ../../doc ${WRKSRC}/doc
	${LN} -s ../../po ${WRKSRC}/po
	${RM} ${WRKSRC}/po/*/digikam.po ${WRKSRC}/po/*/libkgeomap.po

.include <bsd.port.mk>
