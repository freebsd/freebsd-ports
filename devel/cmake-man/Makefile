PORTNAME=	cmake
DISTVERSION=	${_CMAKE_VERSION}
CATEGORIES=	devel
PKGNAMESUFFIX=	-man

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Manual pages for CMake
WWW=		https://www.cmake.org/

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}

USES=		cmake python:build
USE_LOCALE=	en_US.UTF-8

CMAKE_ARGS=	-DCMAKE_DOC_DIR:STRING="${DOCSDIR_REL}" \
		-DCMAKE_MAN_DIR:STRING="share/man"
CMAKE_ON=	SPHINX_MAN
CMAKE_OFF=	SPHINX_HTML SPHINX_QTHELP
CMAKE_SOURCE_PATH=	${WRKSRC}/Utilities/Sphinx

ALL_TARGET=	documentation
INSTALL_TARGET=	install

NO_ARCH=	yes

DISTINFO_FILE=	${.CURDIR}/../cmake-core/distinfo
PLIST_SUB=	CMAKEVERSION="${DISTVERSION:S/.//g:C/-.*//}"

post-install:
# Installed by devel/cmake-gui
	@${RM} ${STAGEDIR}${PREFIX}/share/man/man1/cmake-gui.1

.include <bsd.port.mk>
