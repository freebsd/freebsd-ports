# $FreeBSD$

PORTNAME=	ktuberling
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm emoticons guiaddons i18n \
		iconthemes init itemmodels itemviews jobwidgets \
		kdelibs4support kio libkdegames newstuff notifications \
		notifyconfig parts service solid sonnet textwidgets \
		unitconversion widgetsaddons windowsystem xmlgui
USE_QT=		core dbus declarative gui multimedia network phonon4 printsupport \
		svg testlib widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
