# Created by: Shane Ambler
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	graphics multimedia python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	OpenImageIO python bindings

MASTERDIR=	${.CURDIR}/../openimageio
OPTIONS_EXCLUDE=DOCS IMAGEVIEWER OCIO

do-install:
	@${MKDIR} -p ${STAGEDIR}${PYTHON_SITELIBDIR}
	${INSTALL_LIB} ${BUILD_WRKSRC}/src/python/OpenImageIO.so ${STAGEDIR}${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
