# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	extra-cmake-modules
PORTVERSION=	5.26.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	Extra modules and scripts for CMake

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING-CMAKE-SCRIPTS

USE_GITHUB=	yes
GH_ACCOUNT=	KDE

USES=		cmake
DOCS_USE=	QT5=help
TEST_USE=	QT5=buildtools_build,linguisttools_build,qmake_build
NO_ARCH=	yes

## options

OPTIONS_DEFINE=	DOCS HELP MANPAGES TEST
OPTIONS_DEFAULT=HELP MANPAGES TEST # TEST=off fails: https://bugs.kde.org/show_bug.cgi?id=366110
OPTIONS_SUB=	yes

HELP_DESC=	Generate QtHelp documentation for installed modules

SPHINX_DEP=		sphinx-build:textproc/py-sphinx
DOCS_BUILD_DEPENDS=	${SPHINX_DEP}
HELP_BUILD_DEPENDS=	${SPHINX_DEP}
MANPAGES_BUILD_DEPENDS=	${SPHINX_DEP}
DOCS_CMAKE_ON=		-DBUILD_HTML_DOCS:BOOL=ON
DOCS_CMAKE_OFF=		-DBUILD_HTML_DOCS:BOOL=OFF
HELP_CMAKE_ON=		-DBUILD_QTHELP_DOCS:BOOL=ON
HELP_CMAKE_OFF=		-DBUILD_QTHELP_DOCS:BOOL=OFF
MANPAGES_CMAKE_ON=	-DBUILD_MAN_DOCS:BOOL=ON
MANPAGES_CMAKE_OFF=	-DBUILD_MAN_DOCS:BOOL=OFF
TEST_CMAKE_ON=		-DBUILD_TESTING:BOOL=ON
TEST_CMAKE_OFF=		-DBUILD_TESTING:BOOL=OFF

CONFIGURE_ENV+=		CMAKE_PROGRAM_PATH="${LOCALBASE}/bin:${LOCALBASE}/lib/qt5/bin"

MANPAGES_PLIST_FILES=	\
	man/man7/ecm-developer.7.gz \
	man/man7/ecm-find-modules.7.gz \
	man/man7/ecm-kde-modules.7.gz \
	man/man7/ecm-modules.7.gz \
	man/man7/ecm-toolchains.7.gz \
	man/man7/ecm.7.gz

.include <bsd.port.mk>
