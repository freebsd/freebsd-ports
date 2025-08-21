PORTNAME=	kolourpaint
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE paint program
WWW=		http://www.kolourpaint.org

USES=		cmake compiler:c++17-lang desktop-file-utils gettext-tools gl \
		kde:6 qt:6 tar:xz xorg
USE_GL=		opengl
USE_KDE=	bookmarks colorscheme completion config configwidgets \
		coreaddons crash guiaddons i18n itemviews jobwidgets kio \
		libksane service solid widgetsaddons xmlgui \
		ecm:build
USE_LDCONFIG=	yes
USE_QT=		base
USE_XORG=	x11

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
