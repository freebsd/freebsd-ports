PORTNAME=	kbibtex
DISTVERSION=	0.10.0
PORTREVISION=	13
CATEGORIES=	databases kde
MASTER_SITES=	KDE/stable/KBibTeX/${DISTVERSION}

PATCH_SITES=	https://github.com/KDE/kbibtex/commit/
PATCHFILES=	4d9ce600fdd1deb035a26e4f7922d35b2f41beaf.patch:-p1

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Bibliography editor for KDE
WWW=		https://userbase.kde.org/KBibTeX

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libicuuc.so:devel/icu \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools \
		kde:5 pkgconfig qt:5 shared-mime-info tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash i18n iconthemes itemviews jobwidgets kio \
		parts service solid sonnet syntaxhighlighting texteditor \
		textwidgets wallet widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		concurrent core dbus gui location network networkauth \
		widgets xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

CMAKE_OFF=	CMAKE_CXX_EXTENSIONS
CMAKE_ARGS=	-DKDE_INSTALL_MANDIR:PATH=${PREFIX}/share/man

OPTIONS_DEFINE=			WEBENGINE
OPTIONS_DEFAULT_aarch64=	WEBENGINE
OPTIONS_DEFAULT_amd64=		WEBENGINE
OPTIONS_DEFAULT_i386=		WEBENGINE

WEBENGINE_DESC=			Webpage rendering support
WEBENGINE_USE=			QT=declarative,printsupport,webchannel,webengine
WEBENGINE_CMAKE_BOOL_OFF=	CMAKE_DISABLE_FIND_PACKAGE_Qt5WebEngineWidgets

.include <bsd.port.mk>
