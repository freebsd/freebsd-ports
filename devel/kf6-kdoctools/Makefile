PORTNAME=	kdoctools
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Create documentation from DocBook
MAINTAINER=	kde@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS=	${LOCALBASE}/share/xsl/docbook/html/docbook.xsl:textproc/docbook-xsl \
		docbook-xml>0:textproc/docbook-xml

USES=		cmake gettext gnome kde:6 qt:6 tar:xz
USE_GNOME=	libxml2 libxslt
USE_KDE=	archive i18n \
		ecm:build
USE_QT=		base

.include <bsd.port.mk>
