PORTNAME=	kile
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0b4
PORTREVISION=	4
CATEGORIES=	editors kde

MAINTAINER=	kde@FreeBSD.org
COMMENT=	LaTeX source editor for KDE
WWW=		https://kile.sourceforge.io/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpoppler.so:graphics/poppler \
		libpoppler-qt6.so:graphics/poppler-qt6

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext-tools \
		kde:6 qt:6 shared-mime-info shebangfix xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemviews jobwidgets kio okular parts service solid \
		sonnet syntaxhighlighting texteditor textwidgets widgetsaddons \
		windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base
USE_XORG=	x11
SHEBANG_FILES=	*.pl

KDE_INVENT=	ce7af7fc0ea36d275e0bd435d8f484d80310e6ea office

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
