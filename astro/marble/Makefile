# $FreeBSD$

PORTNAME=	marble
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	astro kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Virtual globe and world atlas for KDE

CONFLICTS=	kdeedu-4.4.[0-4]

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 sharedmime
USES=		cmake:outsource gmake
USE_QT4=	corelib dbus declarative designer_build gui network phonon \
		qtestlib script sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_XZ=		yes
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CMAKE_ARGS=	-DMOBILE:BOOL=FALSE

OPTIONS_DEFINE=	GPS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
GPS_DESC=	Support for GPS position provider

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPS}
LIB_DEPENDS+=	gps.20:${PORTSDIR}/astro/gpsd
PLIST_SUB+=	GPS=""
.else
CMAKE_ARGS+=	-DWITH_libgps:BOOL=FALSE
PLIST_SUB+=	GPS="@comment "
.endif

pre-configure:
	${REINPLACE_CMD} -e '/libgps/ s/FIND_PACKAGE/macro_optional_find_package/' \
		${WRKSRC}/src/plugins/positionprovider/CMakeLists.txt

.include <bsd.port.mk>
