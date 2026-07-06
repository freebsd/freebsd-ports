PORTNAME=	kunitconversion
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Converting physical units

USES=		cmake gettext kde:6 qt:6 tar:xz
USE_KDE=	i18n \
		ecm:build
USE_QT=		base tools:build

CMAKE_OFF=	BUILD_PYTHON_BINDINGS

.include <bsd.port.mk>
