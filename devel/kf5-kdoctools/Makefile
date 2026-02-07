PORTNAME=	kdoctools
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 documentation generation from docbook

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake compiler:c++11-lib gettext gnome kde:5 qt:5 tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive i18n \
		ecm:build
USE_QT=		core \
		buildtools:build qmake:build

.include <bsd.port.mk>
