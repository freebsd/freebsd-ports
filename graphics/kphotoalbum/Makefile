PORTNAME=	kphotoalbum
DISTVERSION=	5.12.0
CATEGORIES=	graphics kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Image viewer and organizer for KDE
WWW=		https://www.kphotoalbum.org/

LICENSE=	GPLv2+

LIB_DEPENDS=	libexiv2.so:graphics/exiv2 \
		libvlc.so:multimedia/vlc \
		libKF5KDcraw.so:graphics/libkdcraw

USES=		cmake compiler:c++11-lang desktop-file-utils jpeg kde:5 \
		pkgconfig qt:5 shebangfix tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		i18n iconthemes jobwidgets kio marble phonon purpose service solid \
		sonnet textwidgets widgetsaddons windowsystem xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui location network \
		printsupport sql webchannel widgets xml \
		buildtools:build qmake:build
USE_XORG=	x11
SHEBANG_FILES=	scripts/open-raw.pl scripts/kpa-backup.sh

OPTIONS_DEFINE=	WEBENGINE
OPTIONS_DEFAULT_amd64=	WEBENGINE
OPTIONS_DEFAULT_i386=	WEBENGINE

WEBENGINE_DESC=	Add dependency on qt5-webengine
WEBENGINE_USE=	QT=webengine

.include <bsd.port.mk>
