PORTNAME=	kalarm
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Personal alarm scheduler
WWW=		https://www.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 \
		shebangfix tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kdelibs4support kio \
		notifications notifyconfig parts phonon service solid sonnet textwidgets \
		unitconversion wallet widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime calendarcore \
		calendarutils contacts globalaccel grantleetheme holidays identitymanagement \
		idletime libkdepim mailcommon mailtransport mime \
		pimcommon pimtextedit imap \
		kdepim-runtime5:run
USE_QT=		concurrent core dbus gui network printsupport widgets \
		x11extras xml \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
