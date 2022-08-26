PORTNAME=	libksane
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	graphics kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	SANE library interface for KDE

LIB_DEPENDS=	libsane.so:graphics/sane-backends \
		libKSaneCore.so:graphics/ksanecore

USES=		cmake compiler:c++11-lang gettext kde:5 qt:5 tar:xz
USE_KDE=	config i18n sonnet textwidgets wallet widgetsaddons \
		ecm_build
USE_QT=		core gui widgets \
		buildtools_build qmake_build testlib_build
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

# Override shared library version
KDE_APPLICATIONS_SHLIB_VER=	"${KDE_APPLICATIONS_VERSION}"

.include <bsd.port.mk>
