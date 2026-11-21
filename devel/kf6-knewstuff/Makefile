PORTNAME=	knewstuff
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Framework for downloading and sharing additional application data

USES=		cmake gettext-tools gl kde:6 qt:6 tar:xz
USE_GL=		opengl
USE_KDE=	archive attica config coreaddons i18n package syndication \
		widgetsaddons \
		ecm:build \
		kirigami2:run
USE_QT=		base declarative \
		tools:build

.include <bsd.port.mk>
