PORTNAME=	plasma-sdk
DISTVERSION=	${KDE_PLASMA_VERSION}
CATEGORIES=	devel kde kde-plasma

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Applications useful for Plasma development

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	archive completion config configwidgets coreaddons dbusaddons \
		doctools i18n iconthemes itemmodels kio kirigami2 libplasma \
		plasma5support svg texteditor widgetsaddons \
		ecm:build
USE_QT=		base declarative svg

.include <bsd.port.mk>
