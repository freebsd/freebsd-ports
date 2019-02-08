# $FreeBSD$

PORTNAME=	pim-sieve-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Mail sieve editor

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 tar:xz
USE_KDE=	auth bookmarks codecs config configwidgets coreaddons crash \
		dbusaddons ecm i18n iconthemes kio service wallet \
		widgetsaddons xmlgui
# pim components
USE_KDE+=	libksieve mailtransport pimcommon
USE_QT=		core dbus gui network widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
