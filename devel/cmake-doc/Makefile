# $FreeBSD$

PORTNAME=	cmake
DISTVERSION=	3.10.1
CATEGORIES=	devel
MASTER_SITES=	https://www.cmake.org/files/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-doc

MAINTAINER=	kde@FreeBSD.org
COMMENT=	HTML and Qt Creator helpfiles for CMake

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

DISTINFO_FILE=	${.CURDIR}/../cmake/distinfo

NO_ARCH=	yes
USES=		cmake:outsource
USE_QT5=	help_build

CMAKE_OFF=	SPHINX_MAN
CMAKE_ON=	SPHINX_HTML SPHINX_QTHELP
CMAKE_ARGS=	-DCMAKE_DOC_DIR:STRING="${DOCSDIR_REL}" \
		-DQCOLLECTIONGENERATOR_EXECUTABLE=${QT_BINDIR}/qcollectiongenerator
CMAKE_SOURCE_PATH=	${WRKSRC}/Utilities/Sphinx

ALL_TARGET=	documentation
INSTALL_TARGET=	install

PLIST_SUB=	CMAKEVERSION="${PORTVERSION:S/.//g}"

.include <bsd.port.mk>
