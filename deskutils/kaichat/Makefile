PORTNAME=	kaichat
PORTVERSION=	0.9.0
CATEGORIES=	deskutils
MASTER_SITES=	KDE/stable/kaichat

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Chat interface for AI models such as ollama
WWW=		https://apps.kde.org/kaichat

USES=		cmake gettext-tools kde:6 qt:6 tar:xz
USE_KDE=	crash dbusaddons i18n iconthemes kio ktextaddons \
		notifications notifyconfig purpose sonnet \
		statusnotifieritem userfeedback xmlgui \
		ecm:build doctools:build
USE_QT=		base tools:build
USE_LDCONFIG=	yes

PLIST_SUB=	SHLIB_VER=${PORTVERSION}

.include <bsd.port.mk>
