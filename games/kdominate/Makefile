PORTNAME=	kdominate
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://apps.kde.org/kdominate/

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	config configwidgets coreaddons crash \
		dbusaddons doctools i18n iconthemes \
		libkdegames xmlgui \
		ecm:build
USE_QT=		base declarative svg

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
