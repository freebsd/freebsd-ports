# $FreeBSD$

PORTNAME=	kphotoalbum
DISTVERSION=	5.4.2
PORTREVISION=	1
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libKF5KDcraw.so:graphics/libkdcraw \
		libKF5KGeoMap.so:astro/libkgeomap \
		libKF5Kipi.so:graphics/libkipi

USES=		cmake compiler:c++11-lang jpeg kde:5 pkgconfig qt:5 shebangfix \
		tar:xz
USE_KDE=	archive auth codecs completion config \
		configwidgets coreaddons ecm i18n \
		iconthemes jobwidgets kio marble service \
		sonnet textwidgets widgetsaddons xmlgui
USE_QT=		core dbus gui network phonon4 sql webkit \
		widgets xml \
		buildtools_build qmake_build
SHEBANG_FILES=	scripts/open-raw.pl scripts/kpa-backup.sh

CONFLICTS_INSTALL=	${PORTNAME}-kde4

.include <bsd.port.mk>
