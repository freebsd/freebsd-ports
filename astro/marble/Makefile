# $FreeBSD$

PORTNAME=	marble
PORTVERSION=	${KDE4_VERSION}
CATEGORIES=	astro kde
MASTER_SITES=	KDE/${KDE4_BRANCH}/${PORTVERSION}/src
DIST_SUBDIR=	KDE/${PORTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Virtual globe and world atlas for KDE

LIB_DEPENDS=	libquazip.so:archivers/quazip

USE_KDE4=	kdelibs kdeprefix automoc4
USES=		cmake:outsource gmake shared-mime-info tar:xz
USE_QT4=	corelib dbus declarative designer_build gui network phonon \
		qtestlib script sql svg webkit xml \
		qmake_build moc_build rcc_build uic_build
USE_LDCONFIG=	yes
MAKE_ENV=	XDG_CONFIG_HOME=/dev/null
CMAKE_ARGS=	-DMOBILE:BOOL=FALSE

OPTIONS_DEFINE=	GPS
OPTIONS_DEFAULT=	GPS
OPTIONS_SUB=	yes

GPS_DESC=	Support for GPS position provider
GPS_LIB_DEPENDS=	libgps.so:astro/gpsd
GPS_CMAKE_OFF=	-DWITH_libgps:BOOL=FALSE

# pre-configure:
# # Prevent updating MIME during build.
# 	${REINPLACE_CMD} -e '/update_xdg_mimetypes/ d' \
# 		${PATCH_WRKSRC}/data/CMakeLists.txt

.include <bsd.port.mk>
