PORTNAME=	kate
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	editors kde kde-applications kde-devel

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic editor framework for the KDE system
WWW=		https://kate-editor.org/

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libxkbcommon.so:x11/libxkbcommon

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext gl \
		kde:6 pkgconfig qt:6 tar:xz xorg
USE_KDE=	activities attica5 auth bookmarks codecs colorscheme \
		completion config configwidgets coreaddons crash dbusaddons \
		guiaddons i18n iconthemes itemmodels itemviews jobwidgets kio \
		libplasma newstuff package parts service solid sonnet \
		syntaxhighlighting texteditor textwidgets threadweaver wallet \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_GL=		gl opengl
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
