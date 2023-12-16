PORTNAME=	kamerka
DISTVERSION=	0.20
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Take photos using your webcam and shiny animated QML interface
WWW=		https://dos1.github.io/kamerka/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	v4l_compat>0:multimedia/v4l_compat
LIB_DEPENDS=	libv4l2.so:multimedia/libv4l \
		libqimageblitz.so:x11/qimageblitz

USES=		cmake compiler:c++11-lang kde:5 qt:5 xorg
USE_GITHUB=	yes
GH_ACCOUNT=	dos1
USE_QT=		concurrent core dbus declarative gui network printsupport script xml widgets \
		qmake:build buildtools:build
USE_KDE=	auth bookmarks codecs completion config configwidgets coreaddons crash \
		guiaddons i18n iconthemes init itemviews jobwidgets kdeclarative kdelibs4support \
		kio notifications package parts phonon service solid sonnet textwidgets \
		unitconversion xmlgui widgetsaddons windowsystem \
		doctools:build ecm:build
USE_XORG=	x11

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext-tools

post-patch-NLS-off:
	@${REINPLACE_CMD} 's|IF(NOT GETTEXT_MSGFMT_EXECUTABLE)|IF(TRUE)|' ${WRKSRC}/po/CMakeLists.txt

.include <bsd.port.mk>
