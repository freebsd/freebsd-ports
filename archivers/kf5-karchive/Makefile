# $FreeBSD$

PORTNAME=	karchive
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	archivers kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library that provides classes for handling archive formats

# Sources say LGPL20, KDE policy says LGPL21+, license file is LGPL21
LICENSE=	LGPL20

USES=		cmake compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	ecm
USE_QT=		core \
		buildtools_build qmake_build

.include <bsd.port.mk>
