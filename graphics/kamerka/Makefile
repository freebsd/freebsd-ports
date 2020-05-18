# $FreeBSD$

PORTNAME=	kamerka
DISTVERSION=	0.20
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Take photos using your webcam and shiny animated QML interface

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libv4l2.so:multimedia/libv4l \
		libphonon4qt5.so:multimedia/phonon \
		libqimageblitz.so:x11/qimageblitz

USES=		cmake compiler:c++11-lang kde:5 qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	dos1
USE_QT=		concurrent core dbus declarative gui network printsupport script xml widgets \
		qmake_build buildtools_build
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons crash \
		guiaddons i18n iconthemes init itemviews jobwidgets kdeclarative kdelibs4support \
		kio notifications package parts service solid sonnet textwidgets \
		unitconversion xmlgui widgetsaddons windowsystem

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

post-patch-NLS-off:
	@${REINPLACE_CMD} 's|IF(NOT GETTEXT_MSGFMT_EXECUTABLE)|IF(TRUE)|' ${WRKSRC}/po/CMakeLists.txt

.include <bsd.port.mk>
