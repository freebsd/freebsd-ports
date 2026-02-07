PORTNAME=	kdepim-runtime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM tools and services
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libkolabxml.so:textproc/libkolabxml \
		libqca-qt6.so:devel/qca@qt6 \
		libsasl2.so:security/cyrus-sasl2 \
		libxerces-c.so:textproc/xerces-c3 \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake:noninja compiler:c++11-lib gettext kde:6 qt:6 \
		shared-mime-info tar:xz xorg
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons holidays i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kdav kio \
		notifications notifyconfig parts service solid sonnet \
		textwidgets unitconversion wallet widgetsaddons windowsystem \
		xmlgui \
		ecm:build
# pim components
USE_KDE+=	akonadi akonadicalendar akonadicontacts akonadimime \
		akonadisearch calendarcore calendarutils contacts \
		gapi grantleetheme identitymanagement imap kontactinterface \
		ldap libkdepim mailtransport mbox mime pimcommon pimtextedit \
		syndication
USE_QT=		base networkauth
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang
CXXFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

.include <bsd.port.post.mk>
