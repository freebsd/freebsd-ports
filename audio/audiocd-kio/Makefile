PORTNAME=	audiocd-kio
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE IOSlave for accessing audio CDs
WWW=		https://www.kde.org/

LICENSE=	GPLv2

LIB_DEPENDS=	libFLAC.so:audio/flac \
		libcdda_paranoia.so:audio/cdparanoia \
		libogg.so:audio/libogg \
		libvorbis.so:audio/libvorbis \
		libKCddb6.so:audio/libkcddb \
		libKCompactDisc6.so:audio/libkcompactdisc

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash guiaddons i18n iconthemes itemviews \
		jobwidgets kcmutils kio notifications parts phonon service \
		solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

_${PORTNAME}_PROJECT_VERSION=	5.1
KDE_APPS_BASED_PATCHLEVEL=	${KDE_APPLICATIONS_VERSION:R:S/.//}${KDE_APPLICATIONS_VERSION:E}

OPTIONS_DEFINE=	LAME DOCS
LAME_DESC=	Install LAME MP3 audio encoder
LAME_RUN_DEPENDS=	lame:audio/lame

.include <bsd.port.mk>
