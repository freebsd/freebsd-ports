PORTNAME=	karchive
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	archivers kde kde-frameworks

COMMENT=	Reading, creating, and manipulating file archives
MAINTAINER=	kde@FreeBSD.org

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	ecm:build
USE_QT=		base tools

.include <bsd.port.mk>
