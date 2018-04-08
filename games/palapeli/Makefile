# $FreeBSD$

PORTNAME=	palapeli
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

USES=		cmake:outsource kde:5 shared-mime-info tar:xz
USE_KDE=	archive auth codecs completion config configwidgets coreaddons \
		crash i18n itemviews jobwidgets kio libkdegames notifications service \
		widgetsaddons xmlgui
USE_QT5=	concurrent core dbus gui network svg widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
