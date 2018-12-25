# $FreeBSD$

PORTNAME=	libkdepim
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM Libraries

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_thread.so:devel/boost-libs

USES=		cmake gettext compiler:c++11-lib kde:5 qt:5 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons ecm \
		i18n iconthemes itemmodels itemviews jobwidgets kcmutils \
		kio service wallet widgetsaddons
# pim components
USE_KDE+=	akonadi akonadicontacts akonadisearch contacts  ldap mime
USE_QT=		core dbus designer gui network testlib uiplugin uitools \
		widgets xml \
		buildtools_build qmake_build

USE_LDCONFIG=	yes


OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
