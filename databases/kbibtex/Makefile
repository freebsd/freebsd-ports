PORTNAME=	kbibtex
DISTVERSION=	0.10.50
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/KBibTeX/${DISTVERSION}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bibliography editor
WWW=		https://apps.kde.org/kbibtex/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSES/GPL-2.0-or-later.txt

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools \
		kde:6 pkgconfig python qt:6 shared-mime-info tar:xz xorg
USE_KDE=	config coreaddons crash i18n iconthemes kio \
		parts texteditor textwidgets wallet xmlgui \
		doctools:build ecm:build
USE_QT=		base networkauth
USE_XORG=	x11
USE_LDCONFIG=	yes

KDE_INVENT=	c8d749d01e905a9a96a1b7ff20e7f270b912e2ec office

CMAKE_OFF=	CMAKE_CXX_EXTENSIONS
CMAKE_ARGS=	-DQT_MAJOR_VERSION=6

OPTIONS_DEFINE=			WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE
OPTIONS_DEFAULT_powerpc64le=	WEBENGINE

WEBENGINE_DESC=			Webpage rendering support
WEBENGINE_USE=			QT=declarative,webchannel,webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt6WebEngineWidgets

.include <bsd.port.mk>
