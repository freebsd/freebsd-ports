# $FreeBSD$

PORTNAME=	elisa
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	audio kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Audio player with QML and KDE Plasma integration

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cmake compiler:c++14-lang desktop-file-utils gettext kde:5 \
		pkgconfig qt:5 tar:xz
USE_KDE=	auth baloo5 bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons filemetadata i18n itemviews \
		jobwidgets kcmutils kdeclarative kio kirigami2 package \
		service solid widgetsaddons xmlgui
USE_QT=		buildtools_build qmake_build testlib_build \
		concurrent core dbus declarative gui multimedia network \
		quickcontrols2 sql svg widgets xml

OPTIONS_DEFINE=	DOCS VLC
OPTIONS_DEFAULT=	DOCS VLC

VLC_DESC=		Use VLC instead of QtMultimedia
VLC_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_LIBVLC
VLC_LIB_DEPENDS=	libvlc.so:multimedia/vlc

.include <bsd.port.mk>
