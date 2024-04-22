PORTNAME=	cmake
DISTVERSION=	${_CMAKE_VERSION}
CATEGORIES=	devel
PKGNAMESUFFIX=	-doc

MAINTAINER=	kde@FreeBSD.org
COMMENT=	HTML and Qt Creator helpfiles for CMake
WWW=		https://www.cmake.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx@${PY_FLAVOR}

USES=		cmake python:build qt:6
USE_LOCALE=	en_US.UTF-8
USE_QT=		sqldriver-sqlite:build tools:build

CMAKE_ARGS=	-DCMAKE_DOC_DIR:STRING="${DOCSDIR_REL}" \
		-DQHELPGENERATOR_EXECUTABLE=${QT_TOOLDIR}/qhelpgenerator
CMAKE_ON=	SPHINX_HTML SPHINX_QTHELP
CMAKE_OFF=	SPHINX_MAN
CMAKE_SOURCE_PATH=	${WRKSRC}/Utilities/Sphinx

ALL_TARGET=	documentation
INSTALL_TARGET=	install

NO_ARCH=	yes

DISTINFO_FILE=	${.CURDIR}/../cmake-core/distinfo
PLIST_SUB=	CMAKEVERSION="${DISTVERSION:S/.//g:C/-.*//}"

.include <bsd.port.mk>
