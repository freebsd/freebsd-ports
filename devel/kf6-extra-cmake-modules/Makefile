PORTNAME=	extra-cmake-modules
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Extra modules and scripts for CMake
MAINTAINER=	kde@FreeBSD.org

USES=		cmake kde:6 qt:6 shebangfix tar:xz \
		python:build
USE_QT=		base
INSTALL_TARGET=	install
SHEBANG_FILES=	kde-modules/kde-git-commit-hooks/json-schema.py

PORTDOCS=	html/*

## options

OPTIONS_DEFINE=		DOCS HELP MANPAGES
OPTIONS_DEFAULT=	HELP MANPAGES
OPTIONS_SUB=		yes

HELP_DESC=	Generate QtHelp documentation for installed modules

SPHINX_DEP=		sphinx-build:textproc/py-sphinx
DOCS_BUILD_DEPENDS=	${SPHINX_DEP}
HELP_BUILD_DEPENDS=	${SPHINX_DEP}
MANPAGES_BUILD_DEPENDS=	${SPHINX_DEP}
DOCS_CMAKE_BOOL=	BUILD_HTML_DOCS
HELP_CMAKE_BOOL=	BUILD_QTHELP_DOCS
MANPAGES_CMAKE_BOOL=	BUILD_MAN_DOCS

CONFIGURE_ENV+=	CMAKE_PROGRAM_PATH="${LOCALBASE}/bin:${LOCALBASE}/lib/qt5/bin"
INSTALL_TARGET=	install # does not have install/strip target

.include <bsd.port.mk>
