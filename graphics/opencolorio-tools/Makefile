# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PKGNAMESUFFIX=	-tools

COMMENT=	Tools to work with OpenColorIO profiles

MASTERDIR=	${.CURDIR}/../opencolorio
OPTIONS_EXCLUDE=DOCS

USE_GL=		glew glut

EXTRA_PATCHES=	${FILESDIR}/extra-patch-CMakeLists.txt

.include "${MASTERDIR}/Makefile"
