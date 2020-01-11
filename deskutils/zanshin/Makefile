# $FreeBSD

PORTNAME=	zanshin
DISTVERSION=	0.5.0
PORTREVISION=	6
CATEGORIES=	deskutils kde
MASTER_SITES=	KDE/stable/${PORTNAME}/

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Daily organizer for KDE

LIB_DEPENDS=	libical.so:devel/libical

USES=		cmake compiler:c++14-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	akonadi auth bookmarks codecs completion config configwidgets \
		coreaddons crash ecm guiaddons i18n iconthemes itemmodels \
		itemviews jobwidgets kdelibs4support kio notifications package \
		parts plasma-framework runner service solid sonnet textwidgets \
		unitconversion wallet widgetsaddons windowsystem xmlgui  \
# PIM Components
USE_KDE+=	akonadicalendar akonadicontacts akonadinotes akonadisearch \
		calendarcore contacts identitymanagement kontactinterface ldap \
		mime pimtextedit \
		kdepim-runtime5_run
USE_QT=		concurrent core dbus declarative gui network printsupport testlib \
		widgets xml \
		buildtools_build qmake_build

.include <bsd.port.mk>
