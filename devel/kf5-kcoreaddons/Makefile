PORTNAME=	kcoreaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTEVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtCore

LICENSE=	LGPL21+ BSD3CLAUSE
LICENSE_COMB=	multi

USES=		cmake compiler:c++11-lib kde:5 qt:5 shared-mime-info tar:xz
USE_KDE=	ecm:build
USE_QT=		core dbus linguisttools \
		buildtools:build qmake:build

OPTIONS_DEFINE=		FAM INOTIFY
OPTIONS_DEFAULT=	INOTIFY
OPTIONS_SUB=		yes

INOTIFY_DESC=		Filesystem alteration notifications using inotify
INOTIFY_LIB_DEPENDS=	libinotify.so:devel/libinotify
INOTIFY_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_INOTIFY

# TODO: FAM is broken, and hangs on NFS
FAM_DESC=		Filesystem alteration notifications using fam (broken: hangs on NFS)
FAM_USES=		fam
FAM_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_FAM

CMAKE_ARGS=	-DACCOUNTS_SERVICE_ICON_DIR:PATH=/var/db/AccountsService/icons

.include <bsd.port.mk>
