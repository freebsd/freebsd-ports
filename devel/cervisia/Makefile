# $FreeBSD$

PORTNAME=	cervisia
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CVS Frontend for KDE

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	dbusaddons doctools ecm iconthemes init itemviews kdesu \
		notifications parts widgetsaddons
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
