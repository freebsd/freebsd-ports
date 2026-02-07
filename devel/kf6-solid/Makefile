PORTNAME=	solid
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Desktop hardware abstraction
MAINTAINER=	kde@FreeBSD.org

RUN_DEPENDS=	bsdisks:sysutils/bsdisks

USES=		bison cmake gl kde:6 qt:6 tar:xz
USE_GL=		gl opengl
USE_KDE=	ecm:build
USE_QT=		base tools:build

OPTIONS_DEFINE=	IMOBILE

IMOBILE_DESC=		Apple iPhone/iPod Touch support
IMOBILE_LIB_DEPENDS=	libimobiledevice-1.0.so:comms/libimobiledevice \
			libplist-2.0.so:devel/libplist
IMOBILE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_IMobileDevice \
			CMAKE_DISABLE_FIND_PACKAGE_PList

.include <bsd.port.mk>
