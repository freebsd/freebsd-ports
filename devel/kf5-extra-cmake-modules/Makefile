# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	extra-cmake-modules
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Extra modules and scripts for CMake

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING-CMAKE-SCRIPTS

USES=		cmake:outsource kde:5 tar:xz
USE_QT5=	#

HELP_USE=	QT5=help_build  # qt5-help is only used to build a .qch file.
TEST_USE=	QT5=buildtools_build,linguisttools_build,qmake_build
NO_ARCH=	yes

## options

OPTIONS_DEFINE=	DOCS HELP MANPAGES TEST
OPTIONS_DEFAULT=HELP MANPAGES TEST # TEST=off fails: https://bugs.kde.org/show_bug.cgi?id=366110
OPTIONS_SUB=	yes

HELP_DESC=		Generate QtHelp documentation for installed modules

SPHINX_DEP=		sphinx-build:textproc/py-sphinx
DOCS_BUILD_DEPENDS=	${SPHINX_DEP}
HELP_BUILD_DEPENDS=	${SPHINX_DEP}
MANPAGES_BUILD_DEPENDS=	${SPHINX_DEP}
DOCS_CMAKE_BOOL=	BUILD_HTML_DOCS
HELP_CMAKE_BOOL=	BUILD_QTHELP_DOCS
MANPAGES_CMAKE_BOOL=	BUILD_MAN_DOCS
TEST_CMAKE_BOOL=	BUILD_TESTING

CONFIGURE_ENV+=	CMAKE_PROGRAM_PATH="${LOCALBASE}/bin:${LOCALBASE}/lib/qt5/bin"
INSTALL_TARGET=	install # does not have install/strip target

.include <bsd.port.mk>
