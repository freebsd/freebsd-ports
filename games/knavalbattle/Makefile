# $FreeBSD$

PORTNAME=	knavalbattle
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons dnssd doctools ecm i18n libkdegames sonnet \
		textwidgets widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
