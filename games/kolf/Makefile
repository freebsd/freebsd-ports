# $FreeBSD$

PORTNAME=	kolf
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource kde:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm guiaddons i18n iconthemes \
		itemviews jobwidgets kdelibs4support kio libkdegames \
		notifications parts service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui
USE_QT5=	core dbus gui network phonon4 printsupport qml quick \
		widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
