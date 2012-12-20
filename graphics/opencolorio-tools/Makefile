# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTNAME=	opencolorio
PORTREVISION=	0
PKGNAMESUFFIX=	-tools

COMMENT=	Tools to work with OpenColorIO profiles

LICENSE=	BSD

LIB_DEPENDS=	OpenImageIO:${PORTSDIR}/graphics/openimageio \
		OpenColorIO:${PORTSDIR}/graphics/opencolorio

MASTERDIR=	${.CURDIR}/../opencolorio

CMAKE_ARGS=	-DOCIO_BUILD_APPS:BOOL=ON \
		-DOCIO_BUILD_JNIGLUE:BOOL=OFF \
		-DOCIO_BUILD_NUKE:BOOL=OFF \
		-DOCIO_BUILD_PYGLUE:BOOL=OFF \
		-DOCIO_BUILD_SHARED:BOOL=OFF \
		-DOCIO_BUILD_STATIC:BOOL=OFF \
		-DOCIO_BUILD_DOCS:BOOL=OFF

USE_GL=		glew glut
CFLAGS+=	-L${LOCALBASE}/lib

EXTRA_PATCHES=	${FILESDIR}/extra-patch-CMakeLists.txt

OCIO_TOOLS=	yes

.include "${MASTERDIR}/Makefile"
