PORTNAME=	kde-dev-utils
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	devel kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE development utilities

USES=		cmake compiler:c++11-lang desktop-file-utils gettext-tools gl kde:6 \
		qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	coreaddons i18n kio parts widgetsaddons \
		ecm:build
USE_QT=		base tools \
		declarative:build
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
