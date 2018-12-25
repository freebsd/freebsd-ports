# $FreeBSD$

PORTNAME=	kalarm
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal alarm scheduler

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++11-lib gettext kde:5 qt:5 shebangfix tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons ecm guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kdelibs4support kio \
		notifications parts service solid sonnet textwidgets \
		unitconversion wallet widgetsaddons windowsystem xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime alarmcalendar calendarcore \
		calendarutils contacts holidays identitymanagement \
		kdepim-apps-libs libkdepim mailcommon mailtransport mime \
		pimcommon pimtextedit imap \
		kdepim-runtime5_run
USE_QT=		core dbus gui network phonon4 printsupport widgets x11extras xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

SHEBANG_FILES=	src/kconf_update/kalarm*.pl

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
