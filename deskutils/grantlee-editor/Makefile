PORTNAME=	grantlee-editor
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Editor for Grantlee themes
WWW=		https://www.kde.org/

LICENSE=	LGPL21

LIB_DEPENDS=	libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
# KDE Frameworks
USE_KDE=	archive crash dbusaddons i18n ktextaddons mime \
		syntaxhighlighting xmlgui \
		ecm:build
# KDE PIM
USE_KDE+=	akonadicontacts grantleetheme imap messagelib pimcommon
USE_QT=		base declarative webengine
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
