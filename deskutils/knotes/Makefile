# $FreeBSD$

PORTNAME=	knotes
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Popup notes

LICENSE=	LGPL21

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++11-lib gettext grantlee:5 kde:5 qt:5 tar:xz xorg
USE_KDE=	attica auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons dnssd globalaccel guiaddons i18n \
		iconthemes itemmodels itemviews jobwidgets kcmutils \
		kdelibs4support kio newstuff notifications notifyconfig parts \
		service solid sonnet textwidgets unitconversion widgetsaddons \
		windowsystem xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadinotes akonadisearch  \
		calendarcore calendarutils contacts grantleetheme imap kontactinterface libkdepim \
		mime pimcommon pimtextedit \
		kdepim-runtime5_run
USE_QT=		concurrent core dbus gui network printsupport widgets x11extras xml \
		buildtools_build qmake_build
USE_XORG=	ice sm x11 xext
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
