PORTNAME=	libkdepim
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM Libraries

LICENSE=	LGPL21

BUILD_DEPENDS=	${LOCALBASE}/include/boost/range/algorithm.hpp:devel/boost-libs

USES=		cmake gettext compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons \
		i18n iconthemes itemmodels itemviews jobwidgets kcmutils \
		kio service wallet widgetsaddons \
		ecm_build
# pim components
USE_KDE+=	akonadi akonadicontacts akonadisearch contacts ldap mime
USE_QT=		concurrent core dbus designer gui network uiplugin uitools \
		widgets xml \
		buildtools_build qmake_build testlib_build

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
