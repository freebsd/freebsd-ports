PORTNAME=	kapptemplate
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE template generator

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz xorg
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		doctools i18n jobwidgets kio kirigami-addons newstuff service solid \
		widgetsaddons windowsystem \
		ecm:build
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
