PORTNAME=	korganizer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar and scheduling Program
WWW=		https://www.kde.org/

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++11-lib desktop-file-utils gettext gl kde:6 \
		qt:6 tar:xz xorg
USE_GL=		gl
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kio newstuff \
		notifications parts phonon service solid sonnet textwidgets \
		unitconversion wallet widgetsaddons windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadimime \
		akonadisearch calendarcore calendarsupport \
		calendarutils contacts eventviews grantleetheme holidays \
		identitymanagement imap incidenceeditor kontactinterface ldap \
		libkdepim mailtransport mime pimcommon pimtextedit \
		kdepim-runtime:run
USE_QT=		base
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
