# $FreeBSD$

PORTNAME=	cmake
DISTVERSION=	3.9.6
CATEGORIES=	devel
MASTER_SITES=	https://www.cmake.org/files/v${PORTVERSION:R}/
PKGNAMESUFFIX=	-doc

MAINTAINER=	kde@FreeBSD.org
COMMENT=	HTML and Qt Creator helpfiles for CMake

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/Copyright.txt

DISTINFO_FILE=	${.CURDIR}/../cmake/distinfo

BUILD_DEPENDS=	sphinx-build:textproc/py-sphinx

NO_ARCH=	yes
USES=		cmake:outsource
USE_QT5=	help_build

CMAKE_ARGS=	-DSPHINX_MAN:BOOL=OFF \
		-DSPHINX_HTML:BOOL=ON \
		-DSPHINX_QTHELP:BOOL=ON \
		-DCMAKE_DOC_DIR:STRING="${DOCSDIR_REL}" \
		-DQCOLLECTIONGENERATOR_EXECUTABLE=${QT_BINDIR}/qcollectiongenerator
CMAKE_SOURCE_PATH=	${WRKSRC}/Utilities/Sphinx

ALL_TARGET=	documentation
INSTALL_TARGET=	install

PLIST_SUB=	CMAKEVERSION="${PORTVERSION:S/.//g}"

.include <bsd.port.mk>
