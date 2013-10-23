# Created by: Shane Ambler <FreeBSD@Shaneware.biz>
# $FreeBSD$

PKGNAMESUFFIX=	-tools

COMMENT=	Tools to work with OpenColorIO profiles

MASTERDIR=	${.CURDIR}/../opencolorio
OPTIONS_EXCLUDE=DOCS

USE_GL=		glew glut

EXTRA_PATCHES=	${FILESDIR}/extra-patch-CMakeLists.txt

post-patch:
	@${FIND} ${WRKSRC}/src/apps -name main.cpp | ${XARGS} \
		${REINPLACE_CMD} '/namespace OIIO/d'

.include "${MASTERDIR}/Makefile"
