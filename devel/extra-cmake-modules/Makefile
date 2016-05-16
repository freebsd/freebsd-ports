# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	extra-cmake-modules
PORTVERSION=	5.22.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	yuri@rawbw.com
COMMENT=	Extra modules and scripts for CMake

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING-CMAKE-SCRIPTS

USE_GITHUB=	yes
GH_ACCOUNT=	KDE

USES=		cmake
NO_ARCH=	yes

## options

OPTIONS_DEFINE=	DOCS MANPAGES
OPTIONS_DEFAULT=DOCS MANPAGES

SPHINX_DEP=		sphinx-build:textproc/py-sphinx
DOCS_BUILD_DEPENDS=	${SPHINX_DEP}
MANPAGES_BUILD_DEPENDS=	${SPHINX_DEP}
DOCS_CMAKE_ON=		-DBUILD_HTML_DOCS:BOOL=ON
DOCS_CMAKE_OFF=	        -DBUILD_HTML_DOCS:BOOL=OFF
MANPAGES_CMAKE_ON=	-DBUILD_MAN_DOCS:BOOL=ON
MANPAGES_CMAKE_OFF=	-DBUILD_MAN_DOCS:BOOL=OFF
MANPAGES_PLIST_FILES=	\
	man/man7/ecm-developer.7.gz \
	man/man7/ecm-find-modules.7.gz \
	man/man7/ecm-kde-modules.7.gz \
	man/man7/ecm-modules.7.gz \
	man/man7/ecm-toolchains.7.gz \
	man/man7/ecm.7.gz

.include <bsd.port.mk>
