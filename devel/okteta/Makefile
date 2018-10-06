# $FreeBSD$

PORTNAME=	okteta
DISTVERSION=	0.25.3
PORTEPOCH=	1
CATEGORIES=	devel kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${DISTVERSION}/src

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE hex editor

LIB_DEPENDS=	libqca-qt5.so:devel/qca@qt5

USES=		cmake:outsource gettext kde:5 qt:5 shared-mime-info tar:xz
USE_KDE=	attica auth bookmarks codecs completion crash \
		config configwidgets coreaddons dbusaddons doctools \
		ecm i18n iconthemes itemviews jobwidgets kcmutils kio \
		newstuff parts service solid sonnet textwidgets \
		widgetsaddons xmlgui
USE_QT=		concurrent core dbus designer gui network printsupport qml \
		script scripttools widgets xml \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

.include <bsd.port.mk>
