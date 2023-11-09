PORTNAME=	cmake
DISTVERSION=	${_CMAKE_VERSION}
CATEGORIES=	devel
PKGNAMESUFFIX=	-doc

MAINTAINER=	kde@FreeBSD.org
COMMENT=	HTML and Qt Creator helpfiles for CMake
WWW=		https://www.cmake.org

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

DISTINFO_FILE=	${.CURDIR}/../cmake-core/distinfo

NO_ARCH=	yes
USES=		cmake qt:5
USE_QT=		help:build
USE_LOCALE=	en_US.UTF-8

CMAKE_OFF=	SPHINX_MAN
CMAKE_ON=	SPHINX_HTML SPHINX_QTHELP
CMAKE_ARGS=	-DCMAKE_DOC_DIR:STRING="${DOCSDIR_REL}" \
		-DQHELPGENERATOR_EXECUTABLE=${QT_BINDIR}/qhelpgenerator
CMAKE_SOURCE_PATH=	${WRKSRC}/Utilities/Sphinx

ALL_TARGET=	documentation
INSTALL_TARGET=	install

PLIST_SUB=	CMAKEVERSION="${DISTVERSION:S/.//g:C/-.*//}"

.include <bsd.port.mk>
