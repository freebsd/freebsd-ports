PORTNAME=	plasma-sdk
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	devel kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Applications useful for Plasma development

USES=		cmake gettext gl kde:6 qt:6 tar:xz xorg
USE_KDE=	archive colorscheme completion config configwidgets coreaddons \
		dbusaddons doctools i18n iconthemes itemmodels jobwidgets kio \
		kirigami2 libplasma package parts plasma5support service solid \
		svg syntaxhighlighting texteditor widgetsaddons windowsystem \
		xmlgui \
		ecm:build
USE_QT=		5compat base declarative svg
USE_XORG=	x11
USE_GL=		gl opengl

.include <bsd.port.mk>
