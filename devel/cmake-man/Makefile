PORTNAME=	cmake
DISTVERSION=	${_CMAKE_VERSION}
CATEGORIES=	devel
PKGNAMESUFFIX=	-man

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Manual pages for CMake
WWW=		https://www.cmake.org/

LICENSE=	BSD3CLAUSE

DISTINFO_FILE=	${.CURDIR}/../cmake-core/distinfo

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

USES=		cmake
USE_LOCALE=	en_US.UTF-8

NO_ARCH=	yes
DISTINFO_FILE=	${.CURDIR}/../cmake-core/distinfo

CMAKE_OFF=	SPHINX_HTML SPHINX_QTHELP
CMAKE_ON=	SPHINX_MAN
CMAKE_ARGS=	-DCMAKE_DOC_DIR:STRING="${DOCSDIR_REL}"
CMAKE_SOURCE_PATH=	${WRKSRC}/Utilities/Sphinx

ALL_TARGET=	documentation
INSTALL_TARGET=	install

PLIST_SUB=	CMAKEVERSION="${DISTVERSION:S/.//g:C/-.*//}"

post-install:
# Installed by devel/cmake-gui
	@${RM} ${STAGEDIR}${PREFIX}/man/man1/cmake-gui.1

.include <bsd.port.mk>
