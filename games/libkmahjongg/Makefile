PORTNAME=	libkmahjongg
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	games kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library for the Mahjongg Solitaire for KDE
WWW=		https://www.kde.org/applications/games/kmahjongg/

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	auth codecs completion config configwidgets coreaddons i18n \
		widgetsaddons \
		ecm:build
USE_QT=		base svg
USE_LDCONFIG=	yes

_${PORTNAME}_PROJECT_VERSION=	6.0
PLIST_SUB+=	SHLIB_SHVER="${_${PORTNAME}_PROJECT_VERSION:R}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
