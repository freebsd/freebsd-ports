PORTNAME=	ksirk
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		https://www.kde.org/applications/games/ksirk/

USES=		cmake compiler:c++11-lang kde:5 qca qt:5 tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash i18n iconthemes kio libkdegames newstuff phonon service wallet \
		widgetsaddons xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network svg \
		widgets xml \
		buildtools:build qmake:build testlib:build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
