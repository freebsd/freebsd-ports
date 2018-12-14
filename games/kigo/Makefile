# $FreeBSD$

PORTNAME=	kigo
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm i18n jobwidgets kio \
		libkdegames newstuff notifyconfig service sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
