# $FreeBSD$

PORTNAME=	okteta
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE hex editor

LIB_DEPENDS=	libqca-qt5.so:devel/qca@qt5

USES=		cmake:outsource gettext kde:5 qt:5 shared-mime-info tar:xz
USE_KDE=	attica auth bookmarks codecs completion crash \
		config configwidgets coreaddons dbusaddons doctools \
		ecm i18n iconthemes itemviews jobwidgets kcmutils kio \
		newstuff parts service solid sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		core dbus designer gui network printsupport script scripttools \
		widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

# okteta is no longer released as part of KDE Appplications past 17.12.3
# Until there is a new release, use the last one
KDE_APPLICATIONS_VERSION=	17.12.3

.include <bsd.port.mk>
