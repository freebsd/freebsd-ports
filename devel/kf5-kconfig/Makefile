# $FreeBSD$

PORTNAME=	kconfig
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 widgets for configuration dialogs

# Sources say LGPL20+, KDE policy says LGPL21+, license file is LGPL21
LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

USES=		cmake:outsource compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		buildtools_build concurrent core dbus gui linguisttools \
		qmake_build testlib xml

.include <bsd.port.mk>
