PORTNAME=	extra-cmake-modules
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

COMMENT=	Extra modules and scripts for CMake
MAINTAINER=	kde@FreeBSD.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING-CMAKE-SCRIPTS

USES=		cmake:testing kde:6 shebangfix tar:xz \
		python:build

SHEBANG_FILES=	kde-modules/kde-git-commit-hooks/json-schema.py
INSTALL_TARGET=	install # does not have install/strip target

PORTDOCS=	html/*
DOCSDIR=	${PREFIX}/share/doc/ECM
NO_ARCH=	yes

SPHINX_DEP=	sphinx-build:textproc/py-sphinx
## options

OPTIONS_DEFINE=		DOCS HELP MANPAGES
OPTIONS_DEFAULT=	HELP MANPAGES
OPTIONS_SUB=		yes

DOCS_BUILD_DEPENDS=	${SPHINX_DEP}
DOCS_CMAKE_BOOL=	BUILD_HTML_DOCS

HELP_DESC=		Generate QtHelp documentation for installed modules
HELP_BUILD_DEPENDS=	${SPHINX_DEP}
HELP_BINARY_ALIAS=	qcollectiongenerator=${LOCALBASE}/libexec/qt6/qhelpgenerator
HELP_USES=		qt:6
HELP_USE=		QT=sqldriver-sqlite:build,tools:build
HELP_CMAKE_BOOL=	BUILD_QTHELP_DOCS

MANPAGES_BUILD_DEPENDS=	${SPHINX_DEP}
MANPAGES_CMAKE_BOOL=	BUILD_MAN_DOCS

TESTING_UNSAFE=		requires reuse-tool port

.if exists(/usr/include/sys/inotify.h)
EXTRA_PATCHES+=		${FILESDIR}/extrapatch-inotify
.endif

.include <bsd.port.mk>
