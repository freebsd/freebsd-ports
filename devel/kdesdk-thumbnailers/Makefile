# $FreeBSD$

PORTNAME=	kdesdk-thumbnailers
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE thumbnail generator for gettext po files

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	config ecm i18n kio
USE_QT=		core gui widgets \
		buildtools_build qmake_build

.include <bsd.port.mk>
