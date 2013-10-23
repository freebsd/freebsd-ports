# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PORTREVISION=	0
PKGNAMESUFFIX=	-tools

COMMENT=	Tools to work with OpenColorIO profiles

LIB_DEPENDS=	OpenImageIO:${PORTSDIR}/graphics/openimageio \
		OpenColorIO:${PORTSDIR}/graphics/opencolorio

MASTERDIR=	${.CURDIR}/../opencolorio
OPTIONS_EXCLUDE=DOCS

CMAKE_ARGS=	-DOCIO_BUILD_APPS:BOOL=ON \
		-DOCIO_BUILD_JNIGLUE:BOOL=OFF \
		-DOCIO_BUILD_NUKE:BOOL=OFF \
		-DOCIO_BUILD_PYGLUE:BOOL=OFF \
		-DOCIO_BUILD_SHARED:BOOL=OFF \
		-DOCIO_BUILD_STATIC:BOOL=OFF

USE_GL=		glew glut

EXTRA_PATCHES=	${FILESDIR}/extra-patch-CMakeLists.txt

post-patch:
	@${FIND} ${WRKSRC}/src/apps -name main.cpp | ${XARGS} \
		${REINPLACE_CMD} '/namespace OIIO/d'

.include "${MASTERDIR}/Makefile"
