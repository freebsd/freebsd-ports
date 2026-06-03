PORTNAME=	kate
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	editors kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Basic editor framework for the KDE system
WWW=		https://kate-editor.org/

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml
LIB_DEPENDS=	libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake compiler:c++11-lang cpe desktop-file-utils gettext kde:6 \
		pkgconfig qt:6 tar:xz xorg
USE_KDE=	activities attica auth bookmarks codecs completion config \
		configwidgets coreaddons crash dbusaddons guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets kio libplasma \
		newstuff package parts service solid sonnet syntaxhighlighting \
		texteditor textwidgets threadweaver userfeedback wallet \
		widgetsaddons windowsystem xmlgui \
		doctools:build ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} "s,/bin/bash,/bin/sh," ${WRKSRC}/apps/lib/exec_inspect.sh

.include <bsd.port.mk>
