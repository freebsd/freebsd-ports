PORTNAME=	kpat
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME:tu}_DESC}
WWW=		http://www.kde.org/applications/games/kpatience/

LIB_DEPENDS=	libfreecell-solver.so:games/freecell-solver \
		libblack_hole_solver.so:games/black-hole-solver

USES=		cmake compiler:c++11-lang desktop-file-utils gettext kde:5 pkgconfig \
		qt:5 shared-mime-info tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash dbusaddons guiaddons i18n iconthemes itemviews \
		kdeclarative kio libkdegames newstuff notifyconfig phonon service \
		textwidgets widgetsaddons xmlgui \
		ecm:build
USE_QT=		concurrent core dbus declarative gui network svg widgets xml \
		buildtools:build qmake:build testlib:build
CMAKE_ON=	WITH_BH_SOLVER

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
