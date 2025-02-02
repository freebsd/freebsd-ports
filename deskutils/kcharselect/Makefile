PORTNAME=	kcharselect
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Character selector for KDE
WWW=		https://utils.kde.org/projects/kcharselect/

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth bookmarks codecs config configwidgets coreaddons crash \
		doctools i18n widgetsaddons xmlgui \
		ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
