# $FreeBSD$

PORTNAME=	kcoreaddons
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 addons to QtCore

LICENSE=	LGPL21+ BSD3CLAUSE
LICENSE_COMB=	multi
LICENSE_FILE_LGPL21+=	${WRKSRC}/COPYING.LIB
LICENSE_FILE_BSD3CLAUSE=	${WRKSRC}/COPYING-CMAKE-SCRIPTS

USES=		cmake:outsource compiler:c++11-lib kde:5 shared-mime-info tar:xz
USE_KDE=	ecm
USE_QT5=	buildtools_build core linguisttools qmake_build

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

.include <bsd.port.mk>
