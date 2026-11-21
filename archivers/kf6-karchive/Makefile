PORTNAME=	karchive
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	archivers kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Reading, creating, and manipulating file archives

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		cmake kde:6 pkgconfig qt:6 ssl tar:xz
USE_KDE=	ecm:build
USE_QT=		base \
		tools:build

.include <bsd.port.mk>
