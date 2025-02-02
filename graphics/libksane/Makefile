PORTNAME=	libksane
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SANE library interface for KDE
WWW=		http://www.kipi-plugins.org

LIB_DEPENDS=	libsane.so:graphics/sane-backends \
		libKSaneCore6.so:graphics/ksanecore

USES=		cmake compiler:c++11-lang gettext kde:6 qt:6 tar:xz
USE_KDE=	config i18n sonnet textwidgets wallet widgetsaddons \
		ecm:build
USE_QT=		base
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

# Override shared library version
KDE_APPLICATIONS_SHLIB_VER=	"${KDE_APPLICATIONS_VERSION}"

.include <bsd.port.mk>
