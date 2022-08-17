PORTNAME=	kpackage
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library to load and install packages

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	archive config coreaddons i18n \
		ecm:build
USE_QT=		core dbus xml \
		buildtools:build qmake:build

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS
OPTIONS_SUB=		yes

.include <bsd.port.mk>
