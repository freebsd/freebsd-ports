PORTNAME=	kio-fuse
DISTVERSION=	5.1.1
CATEGORIES=	filesystems sysutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	FUSE Interface for KIO
WWW=		https://invent.kde.org/system/kio-fuse

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-3.0-or-later.txt

USES=		cmake compiler:c++17-lang fuse:3 kde:6 pkgconfig qt:6 tar:xz
USE_KDE=	coreaddons kio \
		ecm:build
USE_QT=		base declarative

PLIST_FILES=	lib/libexec/kio-fuse \
		share/dbus-1/services/org.kde.KIOFuse.service

.include <bsd.port.mk>
