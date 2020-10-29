# $FreeBSD$

PORTNAME=	kphotoalbum
DISTVERSION=	5.7.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libexpat.so:textproc/expat2 \
		libKF5KDcraw.so:graphics/libkdcraw \
		libKF5Kipi.so:graphics/libkipi

USES=		cmake compiler:c++11-lang desktop-file-utils jpeg kde:5 \
		pkgconfig qt:5 shebangfix tar:xz
USE_KDE=	archive auth codecs completion config \
		configwidgets coreaddons ecm i18n \
		iconthemes jobwidgets kio marble purpose service \
		sonnet textwidgets widgetsaddons xmlgui
USE_QT=		concurrent core dbus declarative gui location network phonon4 \
		printsupport sql webchannel widgets xml \
		buildtools_build qmake_build
SHEBANG_FILES=	scripts/open-raw.pl scripts/kpa-backup.sh

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE

WEBENGINE_DESC=	Add dependency on qt5-webengine
WEBENGINE_USE=	QT=webengine

.include <bsd.port.mk>
