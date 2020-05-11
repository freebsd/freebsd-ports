# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	extra-cmake-modules
DISTVERSION=	${KDE_FRAMEWORKS_VERSION}
PORTREVISION=	1
CATEGORIES=	devel kde kde-frameworks

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Extra modules and scripts for CMake

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING-CMAKE-SCRIPTS

USES=		cmake kde:5 qt:5 tar:xz
USE_QT=		linguisttools buildtools_build qmake_build

HELP_USE=	QT=help_build  # qt5-help is only used to build a .qch file.
NO_ARCH=	yes

## options

OPTIONS_DEFINE=	DOCS HELP MANPAGES
OPTIONS_DEFAULT=HELP MANPAGES
OPTIONS_SUB=	yes

HELP_DESC=		Generate QtHelp documentation for installed modules

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
