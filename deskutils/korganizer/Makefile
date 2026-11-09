PORTNAME=	korganizer
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Calendar and scheduling Program
WWW=		https://www.kde.org/

USES=		cmake desktop-file-utils gettext-tools gl kde:6 \
		qt:6 tar:xz xorg
USE_GL=		gl
USE_KDE=	calendarcore contacts coreaddons crash holidays i18n \
		iconthemes itemviews jobwidgets kcmutils ktextaddons \
		mime parts userfeedback xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadi akonadicalendar akonadicontacts calendarsupport \
		calendarutils eventviews incidenceeditor \
		kontactinterface ldap libkdepim mailtransport pimcommon
# KDE Plasma
USE_KDE+=	activities
USE_QT=		base declarative tools
USE_XORG=	x11
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
