# $FreeBSD$

PORTNAME=	cervisia
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	CVS Frontend for KDE

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	dbusaddons doctools ecm iconthemes init itemviews kdesu \
		notifications parts widgetsaddons
USE_QT=		core dbus gui widgets \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
