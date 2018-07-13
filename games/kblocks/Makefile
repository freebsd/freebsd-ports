# $FreeBSD$

PORTNAME=	kblocks
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource gettext kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons crash \
		dbusaddons i18n itemmodels kio libkdegames newstuff \
		notifyconfig textwidgets widgetsaddons windowsystem xmlgui
USE_QT=		core dbus gui network phonon4 qml quick svg testlib widgets xml \
		buildtools_build qmake_build

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
