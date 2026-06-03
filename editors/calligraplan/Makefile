PORTNAME=	calligraplan
DISTVERSION=	4.0.1
CATEGORIES=	editors kde
MASTER_SITES=	KDE/stable/calligraplan
DIST_SUBDIR=	KDE/${PORTNAME}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE Calligra project management application
WWW=		https://www.calligra.org/plan/

LIB_DEPENDS=	libKChart6.so:graphics/kdiagram-qt6 \
		libqca-qt6.so:devel/qca@qt6

USES=		cmake desktop-file-utils gettext kde:6 perl5 qt:6 \
		shared-mime-info tar:xz xorg
USE_KDE=	archive calendarcore config configwidgets \
		coreaddons dbusaddons guiaddons holidays i18n \
		iconthemes itemmodels itemviews jobwidgets \
		kio notifications parts sonnet textwidgets \
		wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base declarative
USE_XORG=	ice sm x11 xext

OPTIONS_DEFINE=	JAVA PLASMA
OPTIONS_DEFAULT=PLASMA

JAVA_DESC=	Java support for MPXJ based import filters
JAVA_USES=	java:run
JAVA_VARS=	JAVA_VERSION=8+

PLASMA_DESC=	KDE Plasma support
PLASMA_USE=	kde=activities

PLIST_SUB=	SHLIB_VER=${DISTVERSION} SHLIB_SHORT=${DISTVERSION:R:R}

.include <bsd.port.mk>
