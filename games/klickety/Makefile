# $FreeBSD$

PORTNAME=	klickety
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	2
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 qt:5 \
		shebangfix tar:xz
SHEBANG_FILES=	klickety-2.0-inherit-ksame-highscore.pl
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons doctools ecm i18n itemviews \
		jobwidgets kio libkdegames notifications notifyconfig service \
		solid widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
