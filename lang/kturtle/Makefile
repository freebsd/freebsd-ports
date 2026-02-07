PORTNAME=	kturtle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	lang education kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Educational programming environment for KDE
WWW=		https://edu.kde.org/kturtle

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	attica auth codecs config configwidgets coreaddons crash i18n \
		itemmodels kio newstuff service sonnet textwidgets \
		widgetsaddons xmlgui \
		doctools:build ecm:build
USE_QT=		base

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
