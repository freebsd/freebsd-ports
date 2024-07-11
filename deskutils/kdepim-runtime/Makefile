PORTNAME=	kdepim-runtime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM tools and services
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libkolabxml.so:textproc/libkolabxml \
		libsasl2.so:security/cyrus-sasl2 \
		libxerces-c-3.2.so:textproc/xerces-c3 \
		libqt5keychain.so:security/qtkeychain@qt5

USES=		cmake:noninja compiler:c++11-lib gettext grantlee:5 kde:5 qca \
		qt:5 shared-mime-info tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons holidays i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kdav kdelibs4support \
		kio kross notifications notifyconfig parts service solid \
		sonnet textwidgets unitconversion wallet widgetsaddons \
		windowsystem xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadimime \
		akonadinotes akonadisearch calendarcore calendarutils contacts \
		gapi grantleetheme identitymanagement imap kontactinterface \
		ldap libkdepim mailtransport mbox mime pimcommon pimtextedit \
		syndication
USE_QT=		concurrent core dbus declarative gui location network \
		networkauth printsupport script speech webchannel webengine \
		widgets xml xmlpatterns \
		buildtools:build qmake:build
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

.include <bsd.port.post.mk>
