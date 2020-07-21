# $FreeBSD$

PORTNAME=	kpeople
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KF5 library providing access to contacts

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	config coreaddons ecm i18n itemviews service widgetsaddons
USE_QT=		core dbus declarative gui network sql widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
