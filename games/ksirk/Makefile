# $FreeBSD$

PORTNAME=	ksirk
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

LIB_DEPENDS=	libqca-qt5.so:devel/qca@qt5

USES=		cmake:outsource kde:5 qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets \
		coreaddons crash i18n iconthemes kio libkdegames newstuff \
		service wallet widgetsaddons xmlgui
USE_QT=		core dbus gui network phonon4 qml quick svg widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
