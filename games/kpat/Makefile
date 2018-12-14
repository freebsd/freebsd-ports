# $FreeBSD$

PORTNAME=	kpat
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	${${PORTNAME}_DESC}

LIB_DEPENDS=	libfreecell-solver.so:games/freecell-solver

USES=		cmake:outsource compiler:c++11-lang gettext kde:5 pkgconfig \
		qt:5 shared-mime-info tar:xz
USE_KDE=	attica auth codecs completion config configwidgets coreaddons \
		crash dbusaddons ecm guiaddons i18n iconthemes itemviews \
		kdeclarative kio libkdegames newstuff notifyconfig service \
		textwidgets widgetsaddons xmlgui
USE_QT=		core dbus declarative gui network phonon4 svg widgets xml \
		buildtools_build qmake_build

OPTIONS_DEFINE=	DOCS

.include <${.CURDIR}/../kdegames/Makefile.common>
.include <bsd.port.mk>
