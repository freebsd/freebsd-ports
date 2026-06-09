PORTNAME=	kcoreaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Qt addon library with a collection of non-GUI utilities

USES=		cmake cpe kde:6 qt:6 shared-mime-info tar:xz
CPE_VENDOR=	kde
USE_KDE=	ecm:build
USE_QT=		base declarative tools

# Requires PySide and Shiboken.
CMAKE_OFF=	BUILD_PYTHON_BINDINGS

OPTIONS_DEFINE=		INOTIFY
OPTIONS_DEFAULT=	INOTIFY

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_INOTIFY

.include <bsd.port.mk>
