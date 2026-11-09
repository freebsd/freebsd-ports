PORTNAME=	kdepim-addons
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM addons
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme \
		libgpgmepp.so:security/gpgmepp \
		libmarkdown.so:textproc/discount

USES=		cmake gettext-tools kde:6 pkgconfig qt:6 tar:xz
# KDE Frameworks
USE_KDE=	calendarcore colorscheme configwidgets contacts \
		dbusaddons guiaddons holidays i18n iconthemes kcmutils \
		kdeclarative ktextaddons mime parts prison \
		syntaxhighlighting texttemplate xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicalendar akonadicontacts \
		akonadiimportwizard calendarsupport calendarutils \
		grantleetheme gravatar identitymanagement imap \
		incidenceeditor kaddressbook kitinerary ldap libkdepim \
		libkleo libksieve mailcommon mailimporter messagelib \
		pimcommon pimtextedit tnef
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base declarative webengine
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

.include <bsd.port.mk>
