# $FreeBSD$

PORTNAME=	kile
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0b3
PORTREVISION=	7
CATEGORIES=	editors kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LaTeX source editor for KDE

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5

USES=		cmake compiler:c++11-lang desktop-file-utils kde:5 \
		qt:5 shared-mime-info shebangfix
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm guiaddons i18n iconthemes \
		init itemviews jobwidgets js khtml kio parts service solid \
		sonnet texteditor textwidgets widgetsaddons windowsystem xmlgui \
		okular
USE_QT=		concurrent core dbus gui network script widgets xml \
		buildtools_build qmake_build
SHEBANG_FILES=	*.pl

USE_GITHUB=	yes
GH_ACCOUNT=	kde

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
