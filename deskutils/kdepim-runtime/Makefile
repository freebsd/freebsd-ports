PORTNAME=	kdepim-runtime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM tools and services
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libqca-qt6.so:devel/qca@qt6 \
		libsasl2.so:security/cyrus-sasl2 \
		libqt6keychain.so:security/qtkeychain@qt6

USES=		cmake:noninja compiler gettext-tools kde:6 qt:6 \
		shared-mime-info tar:xz
# KDE Frameworks
USE_KDE=	calendarcore codecs contacts i18n itemmodels kcmutils \
		kdav mime notifications notifyconfig \
		ecm:build
# KDE PIM
USE_KDE+=	akonadicalendar akonadimime calendarutils gapi \
		identitymanagement ldap mailtransport mbox pimcommon
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base declarative networkauth speech webengine
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == clang && ${COMPILER_VERSION} < 211
CXXFLAGS+=	-Wno-error=enum-constexpr-conversion
.endif

.include <bsd.port.post.mk>
